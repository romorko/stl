#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <random>

class generuj
{
    int min;
    int max;
public:
    generuj(int a, int b):min(a),max(b){;};
    int operator()(){
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 eng(rd()); // seed the generator
        std::uniform_int_distribution<int> distr(20, 50); // define the range
        return distr(eng);
    }
};

int generujCislo();

int main()
{
    using std::cout;
    using std::endl;
    using std::istream_iterator;
    using std::ostream_iterator;
    using std::copy;
    using std::sort;
    using std::string;
    std::vector<int> cisla;
    std::vector<int> cisla1(10);
    std::vector<int> cisla2(15,10);
    std::vector<int> cisla3 {2,4,6,8,10};
    int pole[] ={1,2,3,4,4,3,2,1};
    std::vector<int> cisla4(pole,pole+8);
    for(int i=0;i<10;++i)
    {
        cisla.push_back(i);
    }
    std::cout<<cisla.capacity();
    std::vector<int> cisla5;
    cisla5.reserve(100);
    int pocetPrvkov = cisla.size();
    for(int i=0;i<pocetPrvkov;++i)
    {
        std::cout<<cisla[i]<<std::endl;
    }

    for(auto i:cisla1)
    {
        std::cout<<i<<std::endl;
    }

    for(auto i=cisla.begin();i<cisla.end();++i)
    {
        std::cout<<*i<<" ";
    }

    std::copy(cisla.begin(),cisla.end(),std::ostream_iterator<int>(std::cout," "));
    std::copy(cisla.begin(),cisla.end(),std::back_inserter(cisla5));
    std::ifstream fin("cisla.txt");
    std::ifstream fin1("text.txt");
    //overenie otvorenia ...
    std::copy(std::istream_iterator<int>(fin),std::istream_iterator<int>(),std::back_inserter(cisla5));
    std::copy(cisla5.begin(),cisla5.end(),std::ostream_iterator<int>(std::cout," "));
    std::sort(cisla5.begin(),cisla5.end(),[](auto i, auto j){return i>j;});
    std::copy(cisla5.begin(),cisla5.end(),std::ostream_iterator<int>(std::cout," "));
    std::cout<<std::endl;
    copy(istream_iterator<string>(fin1),istream_iterator<string>(),ostream_iterator<string>(cout,"\n"));
    std::vector<string> slova;
    fin1.close();
    fin1.open("text.txt");
    copy(istream_iterator<string>(fin1),istream_iterator<string>(),std::back_inserter(slova));
    std::copy(slova.begin(),slova.end(),std::ostream_iterator<string>(std::cout,"\n"));
    std::cout<<std::endl;
    sort(slova.begin(),slova.end());
    std::copy(slova.begin(),slova.end(),std::ostream_iterator<string>(std::cout,"\n"));
    std::cout<<std::endl;
    sort(slova.begin(),slova.end(),[](auto i,auto j){return i.size()<j.size();});
    std::copy(slova.begin(),slova.end(),std::ostream_iterator<string>(std::cout,"\n"));
    std::cout<<std::endl;
    std::copy_if(slova.begin(),slova.end(),std::ostream_iterator<string>(std::cout,"\n"),[](auto i){return i.size()>3 && i.size()<5;});
    std::cout<<std::endl;
    cout<<std::count(slova.begin(),slova.end(),"dnes");
    std::cout<<std::endl;
    cout<<std::count_if(slova.begin(),slova.end(),[](auto i){return i.size()>3 && i.size()<5;});
    std::replace(slova.begin(),slova.end(),string{"mame"},string{"xxxxxxxx"});
    std::replace_if(slova.begin(),slova.end(),[](auto i){return i.find("ma")!=string::npos;},string{"am"});
    std::cout<<std::endl;
    cout<<*std::max_element(cisla5.begin(),cisla5.end());
    std::cout<<std::endl;
    cout<<*std::min_element(cisla5.begin(),cisla5.end());
    std::cout<<std::endl;
    std::copy(cisla5.begin(),cisla5.end(),std::ostream_iterator<int>(std::cout," "));
    cisla5.pop_back();
    std::cout<<std::endl;
    cout<<std::accumulate(cisla5.begin(),cisla5.end(),1,[](auto i,auto j) {return i*j;});
    std::cout<<std::endl;
    auto pos=std::find(cisla5.begin(),cisla5.end(),20);
    if(pos==cisla5.end())
    {
        cout<<"nenasiel";
    }
    else
    {
        cout<<*pos;
    }
    auto pos1=std::find_if(cisla5.begin(),cisla5.end(),[](auto i){ return i>20;});
    cout<<*pos1;
    std::generate(cisla1.begin(),cisla1.end(),generuj(10,20));
    std::cout<<std::endl;
    std::copy(cisla1.begin(),cisla1.end(),std::ostream_iterator<int>(std::cout," "));

    return 0;
}

int generujCislo()
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<int> distr(20, 50); // define the range
    return distr(eng); //generate number
}