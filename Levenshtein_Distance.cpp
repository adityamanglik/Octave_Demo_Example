#include<iostream>
#include<string>
//Levenshtein Distance calculation function
unsigned int L_dist(const std::string& s1,std::string& s2)
{
	const std::size_t len1 = s1.size(), len2 = s2.size();
	unsigned int arr[len1 + 1][len2 + 1];
	unsigned int i,j;
	arr[0][0] = 0;
	for(i = 1; i <= len1; ++i) arr[i][0] = i;
	for(i = 1; i <= len2; ++i) arr[0][i] = i;
	for(i = 1; i <= len1; ++i)
		for(j = 1; j <= len2; ++j)
                     arr[i][j] = std::min(std::min(arr[i - 1][j] + 1, arr[i][j - 1] + 1), arr[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
	return arr[len1][len2];
}
//MAIN FUNCTION
int main()
{
	//Declaring random strings to be checked against(Lookup Table)
	std::string str[]={"variable1", "interp", "apogee", "perigee", "breadboard"};//Change strings for different test cases
	std::string test;
	int i=0,num_str=sizeof(str)/sizeof(*str);
	int dist[num_str];
	std::cout<<"Input test string:";
	getline(std::cin,test);
	for(i=0;i<num_str;i++)
		dist[i]=L_dist(str[i],test);
	int min=0;
	for(i=0;i<num_str;i++)
		if(dist[i]<dist[min])
		min=i;
	if(dist[min]>3) 
	{std::cout<<"Too far/New variable test case entered!";return 0;}//Considers possibility of mistake only if matches are close enough, L Distance<=3
	for(i=0;i<num_str;i++)
		if(dist[i]==dist[min]) 
		std::cout<<"Did you mean '"<<str[i]<<"'?"<<std::endl;//Considers the case for inputs with equal L Distance
	return 0;
}


