


vector<int> findPrime(int num)
{
	vector<int> vec(num+1,1);
	vec[0] = 0;
	vec[1] = 0;
	for(int i = 2; i <= sqrt(num); i++)
	{
		if(vec[i])
			for(int j = i*i; j <= num; j += i)
				vec[j] = 0;
	}
	return vec;

}

