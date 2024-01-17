// For functions "grayscale", "sepia", "reflect", "blur": https://cs50.harvard.edu/x/2023/psets/4/filter/less/
// For function "edges": https://cs50.harvard.edu/x/2023/psets/4/filter/more/
// Execute: ./filter -g image.bmp outfile.bmp
// Execute: ./filter -s image.bmp outfile.bmp
// Execute: ./filter -r image.bmp outfile.bmp
// Execute: ./filter -b image.bmp outfile.bmp
// Execute: ./filter -e image.bmp outfile.bmp
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // So long as the red, green, and blue values ​​are all equal, the result will be varying shades of gray along the black-white spectrum, with higher values ​​meaning lighter shades (closer to white) and lower values ​​meaning darker shades (closer to black).
    // Because the old image is chromatic, the red, green, and blue values of each pixel are different. To ensure each pixel of the new image still has the same general brightness or darkness as the old image, we can take the average of the red, green, and blue value to determine what shade of grey to make the new pixel.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Don't use "BYTE" for declaration, because it's actuall "uint8_t". The value of uint8_t is simply cycle from 0 to 255 and not greater than 255.
            // Divide by "3.0" instead of "3" to transfer data type as float.
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen+ image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue  = avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //  Convert an image to sepia by computing a new RGB value for each pixel based on the original RGB values ​​and formulas.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Note that the value of "BYTE" ("uint8_t") is simply cycle from 0 to 255.
            int originalRed = image[i][j].rgbtRed, originalGreen = image[i][j].rgbtGreen, originalBlue = image[i][j].rgbtBlue;
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)  // Make sure each RGB value is not larger than 255.
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Here we use the "box blur" method for blurring, which works by taking each pixel and, for each color value, giving it a new value by averaging the color values of neighboring pixels.
    RGBTRIPLE temp[height][width]; // Be careful don't declare the non-array "temp" for overwriting:
                                   // If you declare the non-array "temp" to store the new RGB value and overwrite the old one​​,
                                   // you can't get nearby old RGB values ​​to compute the correct new ones.

    for (int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            float count = 0.0;
            int total_r, total_g, total_b;
            total_r = total_g = total_b = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int current_x = i + x, current_y = j +y;

                    if (current_x < 0 || current_x > (height - 1) || current_y < 0 || current_y > (width - 1))
                    {
                        continue;
                    }

                    total_r += image[current_x][current_y].rgbtRed;
                    total_g += image[current_x][current_y].rgbtGreen;
                    total_b += image[current_x][current_y].rgbtBlue;
                    count++;
                }
            }

            temp[i][j].rgbtRed = round(total_r / count);
            temp[i][j].rgbtGreen = round(total_g / count);
            temp[i][j].rgbtBlue = round(total_b / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Gx_red = 0, Gx_green = 0, Gx_blue = 0, Gy_red = 0, Gy_green = 0, Gy_blue = 0;  // Declare "float" for computing square root.
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int current_x = i + x, current_y = j + y;

                    if (current_x < 0 || current_x >= height || current_y < 0 || current_y >= width)
                    {
                        continue;
                    }

                    Gx_red += image[current_x][current_y].rgbtRed * Gx[x+1][y+1];
                    Gx_green += image[current_x][current_y].rgbtGreen * Gx[x+1][y+1];
                    Gx_blue += image[current_x][current_y].rgbtBlue * Gx[x+1][y+1];
                    Gy_red += image[current_x][current_y].rgbtRed * Gy[x+1][y+1];
                    Gy_green += image[current_x][current_y].rgbtGreen * Gy[x+1][y+1];
                    Gy_blue += image[current_x][current_y].rgbtBlue * Gy[x+1][y+1];
                }
            }

            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            if (red > 255)
                red = 255;
            if (green > 255)
                green = 255;
            if (blue > 255)
                blue = 255;

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}