

int rejectionSampling()
{
	while(1)
	{
		int num = 7*(rand7()-1) + (rand7()-1);
		if(num < 40)
			return num % 10 + 1;
	}
}