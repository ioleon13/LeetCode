

int rejectionSampling()
{
	while(1)
	{
		int num = 7*(rand7()-1) + (rand7()-1);
		if(num < 45)
			return num % 9 + 1;
	}
}