#include <iostream>
#include <vector>

static int primeCount = 0;

bool isPrime(int val)
{
    if (val <= 1) return false;

    int divisorCount = 0;
    for(int i = 1; i <= val; i++)
    {
        if (val % i == 0)
        {
            divisorCount++;
        }
    }
    if(divisorCount == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::vector<int> vctr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> primeNumbers;
    vctr.push_back(11);
    vctr.push_back(12); 
    vctr.push_back(13);
    vctr.push_back(14);
    vctr.push_back(15);
    

    for(auto& val : vctr)
    {
        if(isPrime(val))
        {
            primeCount++;
            primeNumbers.push_back(val);
        }
    }
    std::cout << "The number of prime numbers found is: " << primeCount << std::endl;
    std::cout << "The prime numbers are: " << std::endl;
    for(auto& val : primeNumbers)
    {
        std::cout << val << " ";
    }
    
    return 0;


}