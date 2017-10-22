#include <stdio.h>

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;

#pragma pack(1)
typedef struct tagBITMAPFILEHEADER {
	WORD bfType;
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
} BITMAPFILEHEADER;
#pragma pack()

#pragma pack(1)
typedef struct tagBITMAPINFOHEADER {
	DWORD biSize;
	LONG biWidth;
	LONG biHeight;
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	LONG biXPelsPerMeter;
	LONG biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} BITMAPINFOHEADER;
#pragma pack()

void Clamp(short*);

int main()
{
	int restartFileChoosing = 1;

	do {
		FILE *sourceFile;
		BITMAPFILEHEADER bmFileHeader;
		BITMAPINFOHEADER bmInfoHeader;
		unsigned char *image;

		int restartFilterChoosing = 1;

		{
			char* pathsource = malloc(sizeof(char) * 64);
			printf("Enter path to source file : \n");
			scanf("%s", pathsource);
			sourceFile = fopen(pathsource, "rb");
			free(pathsource);
		}

		if (sourceFile == NULL)
		{
			printf("Wrong path!\n");
			continue;
		}

		fread(&bmFileHeader, sizeof(BITMAPFILEHEADER), 1, sourceFile);
		if (bmFileHeader.bfType != 0x4D42)
		{
			printf("Wrong file header type!\n");
			continue;
		}

		fread(&bmInfoHeader, sizeof(BITMAPINFOHEADER), 1, sourceFile);
		if (bmInfoHeader.biSize != 0x28)
		{
			printf("Wrong info header size!\n");
			continue;
		}

		fseek(sourceFile, bmFileHeader.bfOffBits, SEEK_SET);

		image = (unsigned char*)malloc(bmInfoHeader.biSizeImage);
		if (!image)
		{
			free(image);
			continue;
		}
		
		// read 
		fread(image, bmInfoHeader.biSizeImage, 1, sourceFile);
		if (image == NULL)
		{
			continue;
		}

		// choosing filter
		do {

			int filter = 0;
			FILE *targetFile;
			int width = bmInfoHeader.biWidth;
			int height = bmInfoHeader.biHeight;

			{
				char* pathtarget = malloc(sizeof(char) * 64);
				printf("Enter path to target file : \n");
				scanf("%s", pathtarget);
				targetFile = fopen(pathtarget, "wb");
				free(pathtarget);
			}

			printf("Choose filter:\n0 = Average3x3 (default)\n1 = Gaussian3x3\n2 = Sobel X\n3 = Sobel Y\n4 = GreyScale\n");
			scanf("%d", &filter);

			switch (filter)
			{
			case 1: // gaussian3x3

				break;
			case 2: // sobelx

				break;
			case 3: // sobely

				break;
			case 4: // greyscale

				break;
			default: // avg3x3

				break;
			}

			// writing to file
			unsigned char bmpfileheader[14] = 
			{ 
				'B', 'M', 
				0, 0, 0, 0,
				0, 0, 
				0, 0, 
				54, 0, 0, 0 
			};
			unsigned char bmpinfoheader[40] = 
			{ 
				40, 0, 0, 0, 
				0, 0, 0, 0, 
				0, 0, 0, 0, 
				1, 0, 
				24, 0,
				0, 0, 0, 0,
				0, 0, 0, 0,
				0x13, 0x0B, 0, 0,
				0x13, 0x0B, 0, 0,
				0, 0, 0, 0
			};
			unsigned char pad[3] = { 0, 0, 0 };

			int padSize = (4 - (width * 3) % 4) % 4;
			int sizeData = width * height * 3 + height * padSize;
			int fileSize = sizeData + sizeof(targetFile) + sizeof(bmpinfoheader);

			bmpfileheader[2] = (unsigned char)(fileSize);
			bmpfileheader[3] = (unsigned char)(fileSize >> 8);
			bmpfileheader[4] = (unsigned char)(fileSize >> 16);
			bmpfileheader[5] = (unsigned char)(fileSize >> 24);

			bmpinfoheader[4] = (unsigned char)(width);
			bmpinfoheader[5] = (unsigned char)(width >> 8);
			bmpinfoheader[6] = (unsigned char)(width >> 16);
			bmpinfoheader[7] = (unsigned char)(width >> 24);

			bmpinfoheader[8] = (unsigned char)(height);
			bmpinfoheader[9] = (unsigned char)(height >> 8);
			bmpinfoheader[10] = (unsigned char)(height >> 16);
			bmpinfoheader[11] = (unsigned char)(height >> 24);

			bmpinfoheader[20] = (unsigned char)(sizeData);
			bmpinfoheader[21] = (unsigned char)(sizeData >> 8);
			bmpinfoheader[22] = (unsigned char)(sizeData >> 16);
			bmpinfoheader[23] = (unsigned char)(sizeData >> 24);

			fwrite(bmpfileheader, 1, 14, targetFile);
			fwrite(bmpinfoheader, 1, 40, targetFile);

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{
					short r = image[(x + y*width) * 3 + 2];
					short g = image[(x + y*width) * 3 + 1];
					short b = image[(x + y*width) * 3 + 0];

					Clamp(&r);
					Clamp(&g);
					Clamp(&b);

					unsigned char pixel[3];
					pixel[0] = b;
					pixel[1] = g;
					pixel[2] = r;

					fwrite((char*)pixel, 1, 3, targetFile);
				}
				fwrite((char*)pad, padSize, 1, targetFile);
			}

			free(image);
			fclose(targetFile);

			printf("Done!\n");

			restartFilterChoosing = 0;

		} while (restartFilterChoosing != 0);

		fclose(sourceFile);
		restartFileChoosing = 0;

	} while (restartFileChoosing != 0);

	return 0;
}

void Clamp(short *value)
{
	*value = 
		*value < 0 ? 0 : 
		*value > 255 ? 255 : 
		*value;
}