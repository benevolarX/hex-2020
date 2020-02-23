# hex-2020
programmation par contrainte c++

```c++
//exemple de code min/max:  

auto adulte = Min<int>(18); 
int age = 15; 
if (adulte(age)) { 
	std::cout << "adulte"; 
} 
else { 
	std::cout << "enfant"; 
} 

auto ado1 = Min<int>(12) * Max<int>(17); 
auto ado2 = Range<int>(12, 17); 

// autre exemple avec hex switch 

auto sw = HexSwitch<int>();
auto range = Range<int>(5, 7);
auto egal = Equal<int>(9);
auto neg = Negatif<int>();
sw.add_case(&range); // case 0
sw.add_case(&egal); // case 1 
sw.add_case(&neg); // case 2 

switch (sw(6))
{
	case 0 : // [5-7]
		std::cout << "defaut 0";
		break;
	case 1 : // [9]
		std::cout << "defaut 1";
		break;
	case 2 : // [-infini, 0]
		std::cout << "defaut 2";
		break;
	case 3 : 
		std::cout << "defaut 3";
		break;
	default :
		std::cout << "defaut";
		break;
}

// exemple avec string

    auto entier = Digit();
    auto reel = Number();
    auto jean = Regex("^jean$");
    auto minuscule = Lower();
    auto n_ieme_lettre = AtN('A', 1);

    auto sw = HexSwitch<std::string>();
    sw.add_case(&entier); // 0
    sw.add_case(&reel); // 1
    sw.add_case(&jean); // 2
    sw.add_case(&minuscule); // 3
    sw.add_case(&n_ieme_lettre); // 4

    std::string s = "maman";
    switch (sw(s))
    {
    case 0 :
        cout << "entier entre guillemet";
        break;
    case 1 :
        cout << "reel entre guillemet";
        break;
    case 2 :
        cout << "mot jean";
        break;
    case 3 :
        cout << "pas de majuscule";
        break;
    case 4 :
        cout << "la 2eme lettre est A (majuscule)";
        break;
    default :
        cout << "aucun des autres cas";
        break;
}
```


