#pragma once

#include <ace\Time_Value.h>
#include <ace\OS_NS_sys_time.h>
#include <srpc\RpcTypes.h>
#include <srpc\RpcContainers.h>
#include <nsrpc\detail\PacketCoderFactory.h>
#include <nsrpc\..\..\src\CsPacketCoder.h>
#include <nsrpc\..\..\src\p2p\P2pPacketCoder.h>
#include "Common.hpp"

//=========================================================================================================================================

namespace kat
{
	// TEA block cipher
	bool tea_process(const void* src_begin, const void* src_end, void* dst_begin, uint32_t key, void (*func)(uint32_t&, uint32_t&, uint32_t*));
	void tea_encrypt(uint32_t& a, uint32_t& b, uint32_t k[]);
	void tea_decrypt(uint32_t& a, uint32_t& b, uint32_t k[]);

	// CRC32 checksum
	uint32_t crc32(const void* data, size_t size, uint32_t seed);

	// Base of key generator for packet coder
	class CipherKeyGenerator
	{
	public:
		virtual void seedEncrypt(uint32_t seed) { }
		virtual void seedDecrypt(uint32_t seed) { }
		virtual uint32_t nextEncrypt() { return 0; }
		virtual uint32_t nextDecrypt() { return 0; }
		virtual void reset() { }

	};

	// Static key generator for packet coder (custom easy shit)
	class StaticCipherKeyGenerator :
		public CipherKeyGenerator
	{
	public:
		StaticCipherKeyGenerator();
		virtual void seedEncrypt(uint32_t seed) override;
		virtual void seedDecrypt(uint32_t seed) override;
		virtual uint32_t nextEncrypt() override;
		virtual uint32_t nextDecrypt() override;
		virtual void reset() override;

	private:
		uint32_t m_enc_cur;
		uint32_t m_dec_cur;

	};

	// Dynamic key generator for packet coder (probably boost::random::rand48, same as in java)
	class DynamicCipherKeyGenerator :
		public CipherKeyGenerator
	{
	public:
		DynamicCipherKeyGenerator();
		virtual void seedEncrypt(uint32_t seed) override;
		virtual void seedDecrypt(uint32_t seed) override;
		virtual uint32_t nextEncrypt() override;
		virtual uint32_t nextDecrypt() override;
		virtual void reset() override;

	private:
		uint32_t m_unk4;
		uint64_t m_enc_lim;
		uint64_t m_enc_cur;
		uint64_t m_dec_lim;
		uint64_t m_dec_cur;

	};

	// Base of packet cipher
	class PacketCipher
	{
	public:
		virtual size_t getBlockSize() { return 0; }
		virtual bool encrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) { return false; }
		virtual bool decrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) { return false; }
	};

	// TEA Packet cipher
	class TeaPacketCipher :
		public PacketCipher
	{
	public:
		virtual size_t getBlockSize() override { return 8; }
		virtual bool encrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) override;
		virtual bool decrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) override;
	};
	
	// XOR Packet cipher
	class XorPacketCipher :
		public PacketCipher
	{
	public:
		virtual size_t getBlockSize() override { return 0; }
		virtual bool encrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) override;
		virtual bool decrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) override;
	};

	// Custom packet coder
	class SecurePacketCoder :
		public nsrpc::PacketCoder
	{
	public:
		SecurePacketCoder(nsrpc::PacketCoder* base_packet_coder, srpc::String cipher_name, uint32_t key_update_interval, bool dynamic_cipher_key);
		virtual ~SecurePacketCoder() override;
		virtual void reset() override;
		virtual void generateCipherSeed(Seed& encryptSeed, Seed& decryptSeed) const override;
		virtual Seed generateCipherSeed(srpc::UInt32 base) const override;
		virtual void setEncryptSeed(const Seed& seed) override;
		virtual void setDecryptSeed(const Seed& seed) override;
		virtual bool readHeader(nsrpc::AbstractPacketHeader& header, const ACE_Message_Block& mblock) const override;
		virtual bool encode(ACE_Message_Block& mblock, nsrpc::AbstractPacketHeader& header) override;
		virtual bool decode(ACE_Message_Block& mblock) override;
		virtual void extendCipherKeyTimeLimit() override;
		virtual size_t getHeaderSize() const override;
		virtual size_t getDefaultPacketSize() const override;
		virtual size_t getDefaultPacketPoolSize() const override;
		virtual bool shouldExchangeCipherSeed() const override;
		virtual bool isCipherKeyExpired() const override;

	private:
		#pragma pack(push, 1)
		struct PacketHeader
		{
			uint16_t fgprint;
			uint32_t checksum;
		};
		#pragma pack(pop)

		nsrpc::PacketCoder* m_base_packet_coder;
		CipherKeyGenerator* m_cipher_key_generator;
		PacketCipher* m_packet_cipher;
		uint32_t m_key_change_interval;
		uint32_t m_unk14;
		mutable ACE_Time_Value m_key_change_next;

	};

	// Class for creating coders for packets
	class KatPacketCoderFactory :
		public nsrpc::PacketCoderFactory
	{
	public:
		KatPacketCoderFactory(srpc::String cipher_name, uint32_t key_update_interval);
		virtual ~KatPacketCoderFactory() { }
		virtual nsrpc::PacketCoder* create() const;
		virtual nsrpc::PacketCoder* createForP2p() const;

	private:
		srpc::String m_cipher_name;
		uint32_t m_key_update_interval;

	};
}

//=========================================================================================================================================