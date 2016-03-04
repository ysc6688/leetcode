int roma[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
char ch[13][3] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

char* intToRoman(int num)
{
    char *result;
    int iter = 12;

    result = (char *)malloc(100);
    result[0] = 0;

    while(num > 0)
    {
        if(num >= roma[iter])
        {
            strcat(result,ch[iter]);
            num -= roma[iter];
        }
        else
            iter--;
    }
    return result;
}
