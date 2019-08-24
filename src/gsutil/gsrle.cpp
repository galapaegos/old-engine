#include "gsutil/gsrle.h"

namespace gsutil
{
	namespace gsrle
	{
		unsigned long findLength (const unsigned char *src, const unsigned long &srcSize)
		{
			unsigned long loaded = 0;

			unsigned long pos = 0;
			while (pos < srcSize)
			{
				unsigned char s = src[pos + 0];
				unsigned char c = src[pos + 1];

				loaded += s;

				pos += 2;
			}

			return loaded;
		}

		unsigned long loadRLE (const unsigned char *src, const unsigned long &srcSize, unsigned char **dst)
		{
			if (srcSize % 2 != 0)
				return 0;

			unsigned long loaded = 0;

			unsigned long dstSize = findLength (src, srcSize);
			*dst = new unsigned char[dstSize + 1];

			unsigned long pos = 0;
			while (pos < srcSize)
			{
				unsigned char s = src[pos + 0];
				unsigned char c = src[pos + 1];

				for (unsigned int x = 0; x < s; x++)
					(*dst)[loaded++] = c;

				pos += 2;
			}

			return loaded;
		}

		unsigned long saveRLE (unsigned char **dst, const unsigned char *src, const unsigned long &srcSize)
		{
			unsigned long written = 0;

			unsigned char *tmp = new unsigned char[srcSize*2 + 1];
			
			unsigned long pos = 0;
			while (pos < srcSize)
			{
				unsigned char size=0;

				unsigned char count = 0;
				for (unsigned int x = 0; x < 255; x++)
				{
					if (src[pos + x] != src[pos])
						break;
					else
						count ++;
				}

				tmp[written ++] = count;
				tmp[written ++] = src[pos];

				pos += count;
			}

			*dst = new unsigned char[written + 1];
			memcpy (*dst, tmp, written);

			delete [] tmp;

			return written;
		}
	};

	/*
	unsigned int gsrle::loadRLE (unsigned char data[], size_t size, FILE *file)
	{
		unsigned char token;
		unsigned int length;
		unsigned int total = 0;

		while (size && fread (&token, 1, 1, file))
		{
			length = (token & ~0x80) + 1;
			if (length > size)
				return total;
			if (token & 0x80)
			{
				if (!fread (&token, 1, 1, file))
					return total;
				memset (data, token, length);
			}
			else
			{
				if (fread (data, 1, length, file) != length)
					return total;
			}
			data += length, size -= length, total += length;
		}
		return total;
	}

	unsigned int saveRLE (unsigned char data[], size_t size, FILE *file)
	{
		unsigned char token;
		unsigned int i;
		unsigned int total = 0;

		while(size)
		{
			//This loop identifies blocks of repeating data:
			i = 2;
			while (i < size && i < 128 && data[i] == data[i - 1] && data[i - 1] == data[i - 2])
				i++;
			//If repeating data was found, save it:
			if (i > 2)
			{
				token = i - 1 | 0x80;
				if (!fwrite (&token, 1, 1, file))
					return total;
				if (!fwrite (data, 1, 1, file))
					return total;
				data += i, size -= i, total += i;
			}

			//This loop identifies blocks of non-repeating data:
			i = 0;
			while (i < size && i < 128 && (i + 2 > size ? 1 : data[i] != data[i + 1] || data[i + 1] != data[i + 2]))
				i++;
			//If non-repeating data was found, save it:
			if(i)
			{
				token = i - 1;
				if (!fwrite (&token, 1, 1, file))
					return total;
				if (fwrite (data, 1, i, file) != i)
					return total;
				data += i, size -= i, total += i;
			}
		}

		return total;
	}
	*/
};
