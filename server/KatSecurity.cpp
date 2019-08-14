#include "KatSecurity.hpp"
#include "Common.hpp"

//=========================================================================================================================================

bool kat::tea_process(const void* src_begin, const void* src_end, void* dst_begin, uint32_t key, void (*func)(uint32_t&, uint32_t&, uint32_t*))
{
	if (src_begin >= src_end || (((size_t)src_end - (size_t)src_begin) & 7) != 0) // empty or unaligned
	{
		printf("tea failed %p %p\n", src_begin, src_end);
		return false;
	}
	uint32_t keys[4] = { key >> 1, key << 1, key >> 7, key << 7 };
	const uint32_t* src_blk = (const uint32_t*)src_begin;
	uint32_t* dst_blk = (uint32_t*)dst_begin;
	while (src_blk != src_end)
	{
		uint32_t a = *src_blk++;
		uint32_t b = *src_blk++;
		func(a, b, keys);
		*dst_blk++ = a;
		*dst_blk++ = b;
	}
	return true;
}

void kat::tea_encrypt(uint32_t& a, uint32_t& b, uint32_t k[])
{
	uint32_t m = 0;
	for (size_t i = 0; i < 32; i++)
	{
		a += (m + k[m & 3]) ^ (b + ((b << 4) ^ (b >> 5)));
		m -= 0x61C88647;
		b += (m + k[(m >> 11) & 3]) ^ (a + ((a << 4) ^ (a >> 5)));
	}
}

void kat::tea_decrypt(uint32_t& a, uint32_t& b, uint32_t k[])
{
	uint32_t m = 0xC6EF3720;
	for (size_t i = 0; i < 32; i++)
	{
		b -= (m + k[((m >> 11) & 3)]) ^ (a + (16 * a ^ (a >> 5)));
		m += 0x61C88647;
		a -= (m + k[(m & 3)]) ^ (b + (16 * b ^ (b >> 5)));
	}
}

//=========================================================================================================================================

static const uint32_t C_CRC32_PrecomputedTable[] = // by Gary S. Brown.
{
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924, 0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a, 0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236, 0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
};

uint32_t kat::crc32(const void* data, size_t size, uint32_t seed)
{
	uint32_t res = ~seed;
	for (const uint8_t* cur = (const uint8_t*)data; cur != (const uint8_t*)data + size; cur++)
		res = C_CRC32_PrecomputedTable[(uint8_t)res ^ *cur] ^ (res >> 8);
	return ~res;
}

//=========================================================================================================================================

kat::StaticCipherKeyGenerator::StaticCipherKeyGenerator()
{
	reset();
}

void kat::StaticCipherKeyGenerator::seedEncrypt(uint32_t seed)
{
	m_enc_cur = seed;
}

void kat::StaticCipherKeyGenerator::seedDecrypt(uint32_t seed)
{
	m_dec_cur = seed;
}

uint32_t kat::StaticCipherKeyGenerator::nextEncrypt()
{
	return m_enc_cur;
}

uint32_t kat::StaticCipherKeyGenerator::nextDecrypt()
{
	return m_dec_cur;
}

void kat::StaticCipherKeyGenerator::reset()
{
	m_enc_cur = m_dec_cur = 0x20010116; // unknown constant
}

//=========================================================================================================================================

kat::DynamicCipherKeyGenerator::DynamicCipherKeyGenerator()
{
	m_enc_lim = 0x1000000000000;
	m_enc_cur = 0x1330E;
	m_dec_lim = 0x1000000000000;
	m_dec_cur = 0x1330E;
}

void kat::DynamicCipherKeyGenerator::seedEncrypt(uint32_t seed)
{
	uint64_t val = ((uint64_t)seed << 16) | 0x330E;
	m_enc_cur = m_enc_lim ? (val % m_enc_lim) : m_enc_lim; // m_enc_cur can't be 0 tbh
}

void kat::DynamicCipherKeyGenerator::seedDecrypt(uint32_t seed)
{
	uint64_t val = ((uint64_t)seed << 16) | 0x330E;
	m_dec_cur = m_enc_lim ? (val % m_dec_lim) : m_dec_lim; // m_dec_lim can't be 0 tbh
}

uint32_t kat::DynamicCipherKeyGenerator::nextEncrypt()
{
	m_enc_cur = ((0x5DEECE66D * m_enc_cur) + 11) & 0xFFFFFFFFFFFF;
	return (uint32_t)(m_enc_cur >> 17);
}

uint32_t kat::DynamicCipherKeyGenerator::nextDecrypt()
{
	m_dec_cur = ((0x5DEECE66D * m_dec_cur) + 11) & 0xFFFFFFFFFFFF;
	return (uint32_t)(m_dec_cur >> 17);
}

void kat::DynamicCipherKeyGenerator::reset()
{
	m_enc_cur = 0x19720212330E;
	if (m_enc_lim) // can't be 0 tbh
		m_enc_cur %= m_enc_lim; // also useless
	m_dec_cur = 0x19720212330E;
	if (m_dec_lim) // can't be 0 tbh
		m_dec_cur %= m_dec_lim; // also useless
	//LogEx(Logf_Normal, "Reset keygen %llx %llx\n", m_enc_cur, m_dec_cur);
}

//=========================================================================================================================================

bool kat::TeaPacketCipher::encrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key)
{
	return tea_process(src_begin, src_end, dst, key, tea_encrypt);
}

bool kat::TeaPacketCipher::decrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key)
{
	return tea_process(src_begin, src_end, dst, key, tea_decrypt);
}

//=========================================================================================================================================

bool kat::XorPacketCipher::encrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) // 0004
{
	uint8_t key_seed = ((uint8_t*)&key)[0]; // only 2 bytes of key used
	uint8_t shift_seed = (((uint8_t*)&key)[1] % 7) + 1; // clamp shift
	if (shift_seed < 1 || shift_seed > 7) // original check, always falsehood
		return false;
	const uint8_t* src_cur = (const uint8_t*)src_begin;
	uint8_t* dst_cur = (uint8_t*)dst;
	while (src_cur != src_end)
		*dst_cur++ = ROTL8(*src_cur++ ^ key_seed, shift_seed);
	return true;
}

bool kat::XorPacketCipher::decrypt(const void* src_begin, const void* src_end, void* dst, uint32_t key) // 0008
{
	uint8_t key_seed = ((uint8_t*)&key)[0]; // only 2 bytes of key used
	uint8_t shift_seed = (((uint8_t*)&key)[1] % 7) + 1; // clamp shift
	if (shift_seed < 1 || shift_seed > 7) // original check, always falsehood
		return false;
	const uint8_t* src_cur = (const uint8_t*)src_begin;
	uint8_t* dst_cur = (uint8_t*)dst;
	while (src_cur != src_end)
		*dst_cur++ = ROTR8(*src_cur++ ^ key_seed, shift_seed);
	return true;
}

//=========================================================================================================================================

kat::SecurePacketCoder::SecurePacketCoder(nsrpc::PacketCoder* base_packet_coder, srpc::String cipher_name,
	uint32_t key_update_interval, bool dynamic_cipher_key)
{
	m_base_packet_coder = base_packet_coder;
	if (dynamic_cipher_key)
		m_cipher_key_generator = new DynamicCipherKeyGenerator();
	else
		m_cipher_key_generator = new StaticCipherKeyGenerator();
	if (cipher_name.compare("xor") == 0)
		m_packet_cipher = new XorPacketCipher();
	else if (cipher_name.compare("tea") == 0)
		m_packet_cipher = new TeaPacketCipher();
	else
		m_packet_cipher = nullptr;
	m_key_change_interval = key_update_interval;
}

kat::SecurePacketCoder::~SecurePacketCoder()
{
	if (m_base_packet_coder)
		delete m_base_packet_coder;
	if (m_cipher_key_generator)
		delete m_cipher_key_generator;
	if (m_packet_cipher)
		delete m_packet_cipher;
}

void kat::SecurePacketCoder::reset()
{
	if (m_base_packet_coder)
		m_base_packet_coder->reset();
	if (m_cipher_key_generator)
		m_cipher_key_generator->reset();
	extendCipherKeyTimeLimit();
}

void kat::SecurePacketCoder::generateCipherSeed(Seed& encryptSeed, Seed& decryptSeed) const
{
	char buffer[20];

	uint32_t clock1 = (uint32_t)clock();
	uint64_t clock2 = 0x5DEECE66D * ((((uint64_t)(clock1 >> 16)) << 32) | ((uint64_t)((clock1 << 16) | 0x330E)));
	uint64_t clock3 = (((((clock2 + 11) >> 32) & 0xFFFF) << 32) | (uint64_t)((uint32_t)clock2 + 11));

	int32_t enc_seed = (int32_t)(clock3 >> 17);
	snprintf(buffer, 20, "%d", enc_seed);
	encryptSeed = buffer;

	int32_t dec_seed = (int32_t)((((0x5DEECE66D * clock3) + 11) >> 17) & 0x7FFFFFFF);
	snprintf(buffer, 20, "%d", dec_seed);
	decryptSeed = buffer;

	//LogEx(Logf_Normal, "Seeds generated [%s] [%s]\n", encryptSeed.c_str(), decryptSeed.c_str());
}

kat::SecurePacketCoder::Seed kat::SecurePacketCoder::generateCipherSeed(srpc::UInt32 base) const
{
	return PacketCoder::generateCipherSeed(base); // not sure
}

void kat::SecurePacketCoder::setEncryptSeed(const Seed& seed)
{
	int32_t iseed = atol(seed.c_str());
	m_cipher_key_generator->seedEncrypt((uint32_t)iseed);
}

void kat::SecurePacketCoder::setDecryptSeed(const Seed& seed)
{
	int32_t iseed = atol(seed.c_str());
	m_cipher_key_generator->seedDecrypt((uint32_t)iseed);
}

bool kat::SecurePacketCoder::readHeader(nsrpc::AbstractPacketHeader& header, const ACE_Message_Block& mblock) const
{
	return m_base_packet_coder->readHeader(header, mblock);
}

bool kat::SecurePacketCoder::encode(ACE_Message_Block& mblock, nsrpc::AbstractPacketHeader& header)
{
	//LogEx(Logf_Normal, "encoding:\n");
	if (mblock.rd_ptr() != mblock.base())
		return false;
	size_t header_size = getHeaderSize();
	if (mblock.length() <= header_size) // wtf? stupid original check
		return false;
	size_t cipher_block_size = m_packet_cipher->getBlockSize();
	if (cipher_block_size > 0) // align message block
	{
		size_t body_size = mblock.length() - header_size;
		if (body_size % cipher_block_size)
		{
			size_t size_additive = cipher_block_size - (body_size % cipher_block_size);
			mblock.size(mblock.size() + size_additive);
			memset(mblock.wr_ptr(), 0, size_additive);
			mblock.wr_ptr(size_additive);
		}
	}
	header.bodySize_ = (nsrpc::BodySize)(mblock.length() - header_size);
	uint32_t key = m_cipher_key_generator->nextEncrypt();
	uint8_t* body_begin = (uint8_t*)mblock.base() + header_size;
	uint8_t* body_end = (uint8_t*)mblock.wr_ptr();
	uint16_t header_fgprint = (uint16_t)((uint32_t)(key >> 5));
	uint32_t header_checksum = kat::crc32(body_begin, (size_t)body_end - (size_t)body_begin, 0);
	//LogEx(Logf_Normal, " - key=%x, fgprint=%x chksum=%x hdrsize=%zu\n", key, header_fgprint, header_checksum, header_size);
	//LogEx(Logf_Normal, " - original: (%zu)\n", (size_t)body_end - (size_t)body_begin);
	//for (uint8_t* i = body_begin; i != body_end; i++)
	//	LogEx(Logf_Normal, " %02x", *i);
	//LogEx(Logf_Normal, "\n");
	if (!m_packet_cipher->encrypt(body_begin, body_end, body_begin, key)) // encrypt body
		return false;
	//LogEx(Logf_Normal, " - encrypted with cipher\n");
	if (!m_base_packet_coder->encode(mblock, header)) // base cs encode
		return false;
	//LogEx(Logf_Normal, " - encoded with cs coder\n");
	PacketHeader* header_data = (PacketHeader*)(mblock.base() + m_base_packet_coder->getHeaderSize()); // fill overlay header
	header_data->fgprint = header_fgprint;
	header_data->checksum = header_fgprint | header_checksum;
	//LogEx(Logf_Normal, " - final: (%zu)\n", mblock.length());
	//for (size_t i = 0; i < mblock.length(); i++)
	//	LogEx(Logf_Normal, " %02x", (uint8_t)mblock.base()[i]);
	//LogEx(Logf_Normal, "\n");
	if (mblock.rd_ptr() != mblock.base())
		return false;
	//LogEx(Logf_Normal, " - ok\n");
	return true;
}

bool kat::SecurePacketCoder::decode(ACE_Message_Block& mblock)
{
	//LogEx(Logf_Normal, "decoding:\n");
	if (mblock.rd_ptr() != mblock.base())
		return false;
	if (!m_base_packet_coder->decode(mblock)) // base cs decode
		return false;
	//LogEx(Logf_Normal, " - decoded witht cs coder\n");
	PacketHeader* header_data = (PacketHeader*)(mblock.base() + m_base_packet_coder->getHeaderSize());
	uint32_t key = m_cipher_key_generator->nextDecrypt();
	uint16_t header_fgprint = (uint16_t)((uint32_t)(key >> 5));
	//LogEx(Logf_Normal, " - key=%x fgprint=%x/%x\n", key, header_data->fgprint, header_fgprint);
	if (header_data->fgprint != header_fgprint) // verify fingerprint
		return false;
	uint8_t* body_begin = (uint8_t*)mblock.base() + getHeaderSize();
	uint8_t* body_end = (uint8_t*)mblock.wr_ptr();
	//LogEx(Logf_Normal, " - body: (%zu)\n", (size_t)body_end - (size_t)body_begin);
	//for (uint8_t* i = body_begin; i != body_end; i++)
	//	LogEx(Logf_Normal, " %02x", *i);
	//LogEx(Logf_Normal, "\n");
	if (!m_packet_cipher->decrypt(body_begin, body_end, body_begin, key)) // decrypt body
		return false;
	//LogEx(Logf_Normal, " - decrypted: (%zu)\n", (size_t)body_end - (size_t)body_begin);
	//for (uint8_t* i = body_begin; i != body_end; i++)
	//	LogEx(Logf_Normal, " %02x", *i);
	//LogEx(Logf_Normal, "\n");
	uint32_t header_checksum = header_fgprint | kat::crc32(body_begin, (size_t)body_end - (size_t)body_begin, 0);
	//LogEx(Logf_Normal, " - chksum=%x/%x\n", header_data->checksum, header_checksum);
	if (header_data->checksum != header_checksum) // verify checksum
		return false;
	if (mblock.rd_ptr() != mblock.base())
		return false;
	//LogEx(Logf_Normal, " - ok\n");
	return true;
}

void kat::SecurePacketCoder::extendCipherKeyTimeLimit()
{
	ACE_Time_Value interval;
	interval.msec((uint64_t)m_key_change_interval);
	ACE_Time_Value current = ACE_OS::gettimeofday();
	m_key_change_next = current + interval;
}

size_t kat::SecurePacketCoder::getHeaderSize() const
{
	constexpr size_t ff = sizeof(PacketHeader);
	return m_base_packet_coder->getHeaderSize() + sizeof(PacketHeader);
}

size_t kat::SecurePacketCoder::getDefaultPacketSize() const
{
	return m_base_packet_coder->getDefaultPacketSize();
}

size_t kat::SecurePacketCoder::getDefaultPacketPoolSize() const
{
	return m_base_packet_coder->getDefaultPacketPoolSize();
}

bool kat::SecurePacketCoder::shouldExchangeCipherSeed() const
{
	return m_key_change_interval > 0;
}

bool kat::SecurePacketCoder::isCipherKeyExpired() const
{
	if (!m_key_change_interval) // not original check, to disable key exchangement at all
		return false;
	ACE_Time_Value current = ACE_OS::gettimeofday();
	ACE_Time_Value diff = m_key_change_next - current;
	bool expired = (int32_t)diff.msec() < 0; // fixed variant, devs made a mistake here
	//if (expired)
	//	LogEx(Logf_Normal, "Keys will be updated %d\n", (int32_t)diff.msec());
	return expired;
}

//=========================================================================================================================================

kat::KatPacketCoderFactory::KatPacketCoderFactory(srpc::String cipher_name, uint32_t key_update_interval)
{
	m_cipher_name = cipher_name;
	m_key_update_interval = key_update_interval;
}

nsrpc::PacketCoder* kat::KatPacketCoderFactory::create() const
{
	nsrpc::CsPacketCoder* base_packet_coder = new nsrpc::CsPacketCoder();
	if (!base_packet_coder)
		return nullptr;
	if (m_cipher_name.compare("tea") == 0 || m_cipher_name.compare("xor") == 0)
		return new SecurePacketCoder(base_packet_coder, m_cipher_name, m_key_update_interval, true);
	else
		return base_packet_coder;
}

nsrpc::PacketCoder* kat::KatPacketCoderFactory::createForP2p() const
{
	nsrpc::P2pPacketCoder* base_packet_coder = new nsrpc::P2pPacketCoder();
	if (!base_packet_coder)
		return nullptr;
	if (m_cipher_name.compare("tea") == 0 || m_cipher_name.compare("xor") == 0)
		return new SecurePacketCoder(base_packet_coder, m_cipher_name, 0, false);
	else
		return base_packet_coder;
}

//=========================================================================================================================================