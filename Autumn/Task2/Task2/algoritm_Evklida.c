int nodNumbers(int x, int y)
{
	int nominator = 0;
	int denominator = 0;
	if (x > y)
	{
		nominator = x;
		denominator = y;
	}
	else
	{
		nominator = y;
		denominator = x;
	}
	if (nominator % denominator != 0)
	{ 
		return nodNumbers(denominator, nominator % denominator);
	}
	else
	{
		return denominator;
	}
}