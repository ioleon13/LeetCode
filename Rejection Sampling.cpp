

int rejectionSampling()
{
	while(1)
	{
		int num = 7*(rand7()-1) + (rand7()-1);
		if(num < 40)
			return num % 10 + 1;
	}
}


int rejectionSamplingBetter()
{
	while(1)
	{
		int num = 7*(rand7()-1) + (rand7()-1);
		if(num < 40)
			return num % 10 + 1;
		num = 7*(num-40) + (rand7()-1);
		if(n < 60)
			return num % 10 + 1;
		num = 7*(num-60) + (rand7()-1);
		if(n < 20)
			return num % 10 + 1;
	}

}