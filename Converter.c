#include <stdio.h>
#include <math.h>

void scan(double*, double*, double*);
double secund(double, double, double);
double radian(double, double, double);
void chiziq();

int main()
{
    double B_burchak, B_daqiqa, B_soniya;//B ya'ni kenglikni e'lon qilamiz
    double L_burchak, L_daqiqa, L_soniya, L_null;//L ya'ni uzunlikni e'lon qilamiz
    double B_radian, l_null, l_sec, l, sinB, cosB, cos2B, B_sec, L_sec, l2, Nl2;//birinchi qadam o'zgaruvchilarini e'lon qilamiz
    double const P = 206264.8, Pi = 3.1415926535;//o'zgarmas qiymatlarni o'zgaruvchilarga biriktirib olamiz
    double N, a0, a3, a4, a5, a6, X, Y;//asosiy formula o'zgaruvchilarini e'lon qilamiz
    int menu;//menyuni boshqarish uchun o'zgaruvchi
    do
    {
    	printf("\t1 -avtomatik kiritish\n\t2 -qo'lda kiritish\n\t0 -chiqish\n");
    	scanf("%i", &menu);
    	switch(menu)
    	{
    		case 2:
    			printf("Zonaning o'q meridianini kiriting: ");
    			scanf("%lf", &L_null);//nuqtamiz nechinchi hududda joylashganini bilish uchun o'sha hudud markaziy meridiani burchak ko'rinishida qabul qilamiz
    			printf("Kenglikning parametrlarini kiriting:\n");
    			scan(&B_burchak, &B_daqiqa, &B_soniya);//kenglikning qiymatlarini foydalanuvchidan qabul qilamiz
    			printf("Uzunlikning parametrlarini kiriting:\n");
    			scan(&L_burchak, &L_daqiqa, &L_soniya);//uzunlikning qiymatlarini foydalanuvchidan qabul qilamiz
    			break;
    		case 1:
			B_burchak = 51;
    			B_daqiqa = 38;
    			B_soniya = 43.9023;
    			L_burchak = 24;
    			L_daqiqa = 02;
    			L_soniya = 13.1360;
    			L_null = 21;
    			break;
    		case 0: return 0;
    		default: printf("Xatolik, iltimos qaytadan urunib ko'ring!");
   	}
    }
    while(menu!=1&&menu!=2);
    B_sec = secund(B_burchak, B_daqiqa, B_soniya); //B'ning qiymatini sekundlarga o'zgartirish  2
    B_radian = radian(B_burchak, B_daqiqa, B_soniya);//B'ning sinus va cosinusini topish uchun uning radianini aniqlab olamiz
    sinB = sin(B_radian);//kenglikning sinusini aniqlaymi  4
    cosB = cos(B_radian);//kenglikning cosinusini aniqlaymiz  5
    cos2B = pow(cosB, 2);//kenglikning cosinusi kvadratini aniqlaymiz  6

    L_sec = secund(L_burchak, L_daqiqa, L_soniya);//uzunlikning barcha qiymatlarini sekundlarda bir manzilda jamlaymiz
    l_null = L_burchak - L_null;//berilgan asosiy meridian qiymatidan nuqda joylashgan qiymatni ayirib l'ni aniqlaymiz
    l_sec = secund(l_null, L_daqiqa, L_soniya);//l'ning qiymatini sekunndlarga o'zgartiramiz  8
    l = l_sec / P;//  9
    N = 6399698.902 - (21562.267 - (108.973 - 0.612 * cos2B) * cos2B) * cos2B;//N'ni aniqlaymiz

    a0 = 32140.404 - (135.3302 - (0.7092 - 0.0040 * cos2B) * cos2B) * cos2B;//  11
    a4 = (0.25 + 0.00252 * cos2B) * cos2B - 0.04166;//  12
    a6 = (0.166 * cos2B - 0.084) * cos2B;//  13
    a3 = (0.3333333 + 0.001123 * cos2B) * cos2B - 0.1666667;//  14
    a5 = 0.0083 - (0.1667 - (0.1968 + 0.0040 * cos2B) * cos2B) * cos2B;//  15

    l2 = pow(l, 2);//  17
    Nl2 = l2 * N;//  18

    X = 6367558.4969 * B_sec / P - (a0 - (0.5 + (a4 + a6 * l2) * l2) * l2 * N) * sinB * cosB;// X ni qiymatini aniqlaymiz  20
    Y = (1 + (a3 + a5 * l2) * l2) * l * N * cosB;//Y'ning qiymatini aniqlaymiz

    for(int i = 0; i<27; i++)
    {
    	if(1 < i && i < 25)
    		chiziq();
    	switch (i)
    	{
    		case 0:  printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n"); break;
    		case 1:  printf("\t\t|%12s|%20s|%25s|\n", "Qadamlar  ", "Formulalar    ", "Natijalar        "); break;
    		case 2:  printf("\t\t|%12s|%20s|   %.3g`%.2g'%.7g\"   \n", "1     ", "B`        ", B_burchak, B_daqiqa, B_soniya); break;
    		case 3:  printf("\t\t|%12s|%20s|   %.14g\"    \n", "2     ", "B\"        ", B_sec); break;
    		case 4:  printf("\t\t|%12s|%20s|   %0.14g  \n", "3     ", "B\"/ro       ", B_sec/P); break;
    		case 5:  printf("\t\t|%12s|%20s|   %0.14g  \n", "4     ", "sin B       ", sinB); break;
    		case 6:  printf("\t\t|%12s|%20s|   %0.14g  \n", "5     ", "cos B       ", cosB); break;
    		case 7:  printf("\t\t|%12s|%20s|   %0.14g  \n", "6     ", "cos^2 B      ", cos2B); break;
    		case 8:  printf("\t\t|%12s|%20s|   %.3g`%g'%.7g\"\n", "7     ", "l`=L-L_0     ", l_null, L_daqiqa, L_soniya); break;
    		case 9:  printf("\t\t|%12s|%20s|   %0.14g  \n", "8     ", "l\"        ", l_sec); break;
    		case 10: printf("\t\t|%12s|%20s|   %0.14g  \n", "9     ", "l=l\"/ro      ", l); break;
    		case 11: printf("\t\t|%12s|%20s|   %0.14g  \n", "10    ", "N         ", N); break;
    		case 12: printf("\t\t|%12s|%20s|   %0.14g  \n", "11    ", "a_0        ", a0); break;
    		case 13: printf("\t\t|%12s|%20s|   %0.14g  \n", "12    ", "a_4        ", a4); break;
    		case 14: printf("\t\t|%12s|%20s|   %0.14g  \n", "13    ", "a_6        ", a6); break;
    		case 15: printf("\t\t|%12s|%20s|   %0.14g  \n", "14    ", "a_3        ", a3); break;
    		case 16: printf("\t\t|%12s|%20s|   %0.14g  \n", "15    ", "a_5        ", a5); break;
    		case 17: printf("\t\t|%12s|%20s|   %0.14g  \n", "16    ", "sin B * cosB    ", sinB * cosB); break;
    		case 18: printf("\t\t|%12s|%20s|   %0.14g  \n", "17    ", "l^2        ", l2); break;
    		case 19: printf("\t\t|%12s|%20s|   %0.14g  \n", "18    ", "Nl^2        ", Nl2); break;
    		case 20: printf("\t\t|%12s|%20s|   %0.14g  \n", "19    ", "6367558,4969B\"/ro\"  ", 6367558.4969 * B_sec / P); break;
    		case 21: printf("\t\t|%12s|%20s|   %0.14g  \n", "20    ", "X         ", X); break;
    		case 22: printf("\t\t|%12s|%20s|   %0.14g  \n", "21    ", "1+(a_3+a_5l^2)l^2  ", 1 + (a3 + a5 * l2) * l2); break;
    		case 23: printf("\t\t|%12s|%20s|   %0.14g  \n", "21    ", "21lcosB      ", (1 + (a3 + a5 * l2) * l2) * l * cosB); break;
    		case 24: printf("\t\t|%12s|%20s|   %0.14g  \n", "21    ", "Y         ", Y); break;
    		case 25: printf("\t\t+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n"); break;
    	}
    }
    scanf("%lf", &N);
}
void scan(double* gr, double* min, double* sec)
{
	printf("\tBurchak: ");
	scanf("%lf", gr);//burchakni qabul qilish
	printf("\tDaqiqa: ");
	scanf("%lf", min);//minutni qabul qilish
	printf("\tSoniya: ");
	scanf("%lf", sec);//sekundni qabul qilish
}
double secund(double gr, double min, double sec)
{
	return (gr * 3600 + min * 60 + sec);
}
double radian(double gr, double min, double sec)
{
	double burchak, radi;
	burchak = (gr + min / 60 + sec / 3600);
	radi = burchak * 3.1415927 / 180;
	return radi;
}
void chiziq()
{
	printf("\t\t|~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
}
