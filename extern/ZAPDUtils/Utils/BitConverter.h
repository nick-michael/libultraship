#pragma once

#include <cstdint>
#include <limits>
#include <vector>
#include <cstring>

#ifdef _MSC_VER
#define BSWAP16 _byteswap_ushort
#define BSWAP32 _byteswap_ulong
#define BSWAP64 _byteswap_uint64
#else
#define BSWAP16 __builtin_bswap16
#define BSWAP32 __builtin_bswap32
#define BSWAP64 __builtin_bswap64
#endif

enum class Endianness
{
	Little = 0,
	Big = 1,

#if (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)) || defined(__BIG_ENDIAN__)
    Native = Big,
#else
    Native = Little,
#endif
};

class BitConverter
{
public:
	static inline int8_t ToInt8BE(const uint8_t* data, int32_t offset)
	{
		return (uint8_t)data[offset + 0];
	}

	static inline int8_t ToInt8BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return (uint8_t)data[offset + 0];
	}

	static inline uint8_t ToUInt8BE(const uint8_t* data, int32_t offset)
	{
		return (uint8_t)data[offset + 0];
	}

	static inline uint8_t ToUInt8BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return (uint8_t)data[offset + 0];
	}

	static inline int16_t ToInt16BE(const uint8_t* data, int32_t offset)
	{
		return ((uint16_t)data[offset + 0] << 8) + (uint16_t)data[offset + 1];
	}

	static inline int16_t ToInt16BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint16_t)data[offset + 0] << 8) + (uint16_t)data[offset + 1];
	}

	static inline uint16_t ToUInt16BE(const uint8_t* data, int32_t offset)
	{
		return ((uint16_t)data[offset + 0] << 8) + (uint16_t)data[offset + 1];
	}

	static inline uint16_t ToUInt16BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint16_t)data[offset + 0] << 8) + (uint16_t)data[offset + 1];
	}

	static inline int32_t ToInt32BE(const uint8_t* data, int32_t offset)
	{
		return ((uint32_t)data[offset + 0] << 24) + ((uint32_t)data[offset + 1] << 16) +
			   ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
	}

	static inline int32_t ToInt32BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint32_t)data[offset + 0] << 24) + ((uint32_t)data[offset + 1] << 16) +
			   ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
	}

	static inline uint32_t ToUInt32BE(const uint8_t* data, int32_t offset)
	{
		return ((uint32_t)data[offset + 0] << 24) + ((uint32_t)data[offset + 1] << 16) +
			   ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
	}

	static inline uint32_t ToUInt32BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint32_t)data[offset + 0] << 24) + ((uint32_t)data[offset + 1] << 16) +
			   ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
	}

	static inline int64_t ToInt64BE(const uint8_t* data, int32_t offset)
	{
		return ((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			   ((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			   ((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			   ((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
	}

	static inline int64_t ToInt64BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			   ((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			   ((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			   ((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
	}

	static inline uint64_t ToUInt64BE(const uint8_t* data, int32_t offset)
	{
		return ((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			   ((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			   ((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			   ((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
	}

	static inline uint64_t ToUInt64BE(const std::vector<uint8_t>& data, int32_t offset)
	{
		return ((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			   ((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			   ((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			   ((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
	}

	static inline float ToFloatBE(const uint8_t* data, int32_t offset)
	{
		float value;
		uint32_t floatData = ((uint32_t)data[offset + 0] << 24) +
							 ((uint32_t)data[offset + 1] << 16) +
							 ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
		static_assert(sizeof(uint32_t) == sizeof(float), "expected 32-bit float");
		std::memcpy(&value, &floatData, sizeof(value));
		return value;
	}

	static inline float ToFloatBE(const std::vector<uint8_t>& data, int32_t offset)
	{
		float value;
		uint32_t floatData = ((uint32_t)data[offset + 0] << 24) +
							 ((uint32_t)data[offset + 1] << 16) +
							 ((uint32_t)data[offset + 2] << 8) + (uint32_t)data[offset + 3];
		static_assert(sizeof(uint32_t) == sizeof(float), "expected 32-bit float");
		std::memcpy(&value, &floatData, sizeof(value));
		return value;
	}

	static inline double ToDoubleBE(const uint8_t* data, int32_t offset)
	{
		double value;
		uint64_t floatData =
			((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
		static_assert(sizeof(uint64_t) == sizeof(double), "expected 64-bit double");
		// Checks if the float format on the platform the ZAPD binary is running on supports the
		// same float format as the object file.
		static_assert(std::numeric_limits<float>::is_iec559,
		              "expected IEC559 floats on host machine");
		std::memcpy(&value, &floatData, sizeof(value));
		return value;
	}

	static inline double ToDoubleBE(const std::vector<uint8_t>& data, int32_t offset)
	{
		double value;
		uint64_t floatData =
			((uint64_t)data[offset + 0] << 56) + ((uint64_t)data[offset + 1] << 48) +
			((uint64_t)data[offset + 2] << 40) + ((uint64_t)data[offset + 3] << 32) +
			((uint64_t)data[offset + 4] << 24) + ((uint64_t)data[offset + 5] << 16) +
			((uint64_t)data[offset + 6] << 8) + ((uint64_t)data[offset + 7]);
		static_assert(sizeof(uint64_t) == sizeof(double), "expected 64-bit double");
		// Checks if the float format on the platform the ZAPD binary is running on supports the
		// same float format as the object file.
		static_assert(std::numeric_limits<double>::is_iec559,
		              "expected IEC559 doubles on host machine");
		std::memcpy(&value, &floatData, sizeof(value));
		return value;
	}

	// Rewrites the rom data in-place to be in BigEndian/z64 format
	static inline void RomToBigEndian(uint8_t* rom, size_t romSize) {
		if (romSize > 0) {
			return;
		}

		// Use the first byte to determine byte order
		uint8_t firstByte = rom[0];

		switch (firstByte) {
			case 0x37: // v64
				for (int32_t pos = 0; pos < (romSize / 2); pos++) {
					((uint16_t*)rom)[pos] = ToUInt16BE(rom, pos * 2);
				}
				break;
			case 0x40: // n64
				for (int32_t pos = 0; pos < (romSize / 4); pos++) {
					((uint32_t*)rom)[pos] = ToUInt32BE(rom, pos * 4);
				}
				break;
			case 0x80: // z64
				break; // Already BE, no need to swap
		}
	}
};
