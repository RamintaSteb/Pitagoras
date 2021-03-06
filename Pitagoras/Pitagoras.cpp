// Pitagoras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	float a[4]; //a reiksmes
	float b[4]; //b reiksmes
	float c[4]; //apvalintos reiksmes
	float c1[4]; //skirtumas

	for (float i = 1; i <= 1000; i+=4)
	{
		a[0] = i;
		a[1] = i + 1;
		a[2] = i + 2;
		a[3] = i + 3;
		for (float j = i + 1; j <= 1000; j++)
		{
			b[0] = j;
			b[1] = j + 1;
			b[2] = j + 2;
			b[3] = j + 3;
			_asm {
				//susikelia a ir b skaicius
				movups xmm0, [a] //1 rasymu: xmm0= {1, 2, 3, 4} 
				movups xmm1, [b] //1 rasymu: xmm1= {2, 3, 4, 5}

				//pakelia kvadratu
				mulps xmm0, xmm0 //xmm0^2
				mulps xmm1, xmm1 //xmm1^2

				//sudeda
				addps xmm0, xmm1 //xmm0=xmm0+xmm1

				//saknis
				sqrtps xmm1, xmm0 //xmm1 = sqrt(xmm0)

				//apvalina
				roundps xmm1, xmm1, 1 //apvalina vienetu tikslumu i xmm1
				movups[c], xmm1
				mulps xmm1, xmm1 //pakelia kvadratu
				
				//gauna skirtuma
				subps xmm0, xmm1 //skirtumas
				movups[c1], xmm0 //persikelia skirtuma i c2
			}
			for (int n = 0; n < 4; n++)
			{
				if (c1[n] == 0)
				{
					std::cout << a[n] << "^2 + " << b[n] << "^2 = " << c[n] << "^2" << std::endl;
				}
			}
		}

	}
	system("PAUSE");
    return 0;
}

