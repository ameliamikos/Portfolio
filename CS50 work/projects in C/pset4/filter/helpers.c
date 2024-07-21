#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //we can take the average of the red, green, and blue values to determine what shade of grey to make the new pixel.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double avgcolor;
            avgcolor = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = round(avgcolor);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalred = image[i][j].rgbtRed;
            int originalgreen = image[i][j].rgbtGreen;
            int originalblue = image[i][j].rgbtBlue;

            int sepiared = round(.393 * originalred + .769 * originalgreen + .189 * originalblue);
            int sepiagreen = round(.349 * originalred + .686 * originalgreen + .168 * originalblue);
            int sepiablue = round(.272 * originalred + .534 * originalgreen + .131 * originalblue);

            if (sepiared >= 256)
            {
                sepiared = 255;
            }

            if (sepiagreen >= 256)
            {
                sepiagreen = 255;
            }

            if (sepiablue >= 256)
            {
                sepiablue = 255;
            }

            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];   //temporary variable for saving og position
            image[i][j] = image[i][width - 1 - j];  //moving j position across row
            image[i][width - 1 - j] = temp; //reassigning position from temp variable
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp [height][width]; //temporary image to implement on
    for (int i = 0; i < height; i++)    //take average of 9 surrounding. [x-1][y], [x+1][y], [x][y-1] etc etc; reassigning [i][j]?
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float count = 0.00;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    //check for valid neighbouring pexels
                    if (currentx < 0 || currentx > (height - 1) || currenty < 0 || currenty > (width - 1))
                    {
                        continue;
                    }

                    //Get the image value
                    total_Red += image[currentx][currenty].rgbtRed;
                    total_Green += image[currentx][currenty].rgbtGreen;
                    total_Blue += image[currentx][currenty].rgbtBlue;

                    count++;
                }

                //do the average of neigbhouring pexels
                temp[i][j].rgbtRed = round(total_Red / count);
                temp[i][j].rgbtGreen = round(total_Green / count);
                temp[i][j].rgbtBlue = round(total_Blue / count);
            }
        }
    }
//copy the blur image to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
