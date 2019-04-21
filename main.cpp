#include "header.h"

int main () {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> range(1, 10);
    std::string temp;
    std::vector<Studentas> A,vargsai;
    int stud_nr=-1; // Studento identifikacijos nr (-1 nes nera dar jokios stud, prasideda nuo 0)
    int ivedimo_pasirinkimas;
    new_line();

    std::cout << "Kaip noretum ivesti visus duomenis?\n1- Ivesti paciam\n2- Nuskaityti is failo kursiokai.txt\n3- Sugeneruoti faila kursiokai.txt ir nuskaityti is jo" << std::endl;
    while (true){   // Laukiam kol pasirenka 1 arba 2
        int temp_nr;
        std::cin >> temp_nr;
        try {
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                throw "Turi ivesti skaiciu!";
            }
            else{
                if (temp_nr==1 or temp_nr==2 or temp_nr==3){
                    ivedimo_pasirinkimas=temp_nr;
                    break;
                }
                else{
                    throw "Netinkamas skaicius.";
                }    
            }
        } catch (const char* e){
            std::cout << e << std::endl;
        }
    }
    std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

    if (ivedimo_pasirinkimas==1)
    {
        int vid_pasirinkimas;
        std::cout << "Kaip noretum skaiciuoti galutini pazymi?\n1- Naudojant vidurki\n2- Naudojant mediana" << std::endl;
        while (true){   // Laukiam kol pasirenka 1 arba 2
            std::cin>>temp;
            if (temp=="1"){
                vid_pasirinkimas=1;
            break;
            }
            else if (temp=="2"){
                vid_pasirinkimas=2;
            break;
            }
            else
            std::cout<< erroras << std::endl;
        }
        std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

        while (true) {
            new_line();
            std::cout << "Ivesk " << stud_nr+2 <<" studento varda ir pavarde. (Vardenis Pavardenis)" << std::endl << "Jei jau pabaigiai vesti duomenis tiesiog spausk ENTER." << std::endl;

            std::getline(std::cin, temp);

            if (!temp.empty())
            {
                int pos = temp.find(" "); // Tarpo pozicija, reikalinga tam, kad atskirti varda nuo pavardes

                if (temp.length()-1>pos and all_letters(temp)==true) { // Tikrinu ar yra ivestas vardas ir pavarde ir nera skaiciu
                    A.push_back(Studentas()); // Pakeiciu array A dydi su kiekvienu tinkamu vardu ir pav
                    stud_nr++; // Paruosiamas nr studentui
                    A[stud_nr].SetVardas(temp.substr(0,pos));
                    A[stud_nr].SetVardas(convert_to_proper_format(A[stud_nr].GetVardas()));
                    A[stud_nr].SetPavarde(temp.substr(pos+1));
                    A[stud_nr].SetPavarde(A[stud_nr].GetPavarde().substr(0,A[stud_nr].GetPavarde().find(" "))); // Palieka 2 pirmus zodzius jei iveda daugiau nei 2
                    A[stud_nr].SetPavarde(convert_to_proper_format(A[stud_nr].GetPavarde()));

                    new_line();
                    std::cout << "Kaip nori ivesti namu darbus rezultatus?\n1- Rankiniu budu\n2- Sugeneruoti automatiskai" << std::endl;
                    std::vector<int> pazymiai;
                    int sk=0; // Namu darbus kiekis
                    while(true){
                        std::cin>>temp;
                    if (temp=="1") {
                        new_line();
                        std::cout << "Ivedinek skaicius 0-10, noredamas sustoti ivesk betkoki kita skaiciu." << std::endl;
                        while(true){
                            std::cin>>temp;
                            if(is_digits(temp)==true)
                            {
                                int ivestis = std::stoi(temp);
                                if (ivestis>=0 and ivestis<=10){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=ivestis;
                                    sk++;
                                }
                                else {
                                    if (sk!=0)
                                        break;
                                    else
                                        std::cout << "Ivesk bent 1 skaiciu..." << std::endl;
                                }
                            } 
                            else
                                std::cout << erroras << std::endl;
                        }
                        break;
                    }
                    if (temp=="2"){
                    new_line();
                    std::cout << "Kiek skaiciu sugeneruoti?" << std::endl;
                    while(true){
                        std::cin>>temp;
                        if(is_digits(temp)==true)
                        {
                            int ivestis = std::stoi(temp);
                            if (ivestis>0){
                                for (int i=0;i<ivestis;i++){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=range(mt);
                                    sk++;
                                }
                                break;
                            }
                            else {
                                if (sk!=0)
                                    break;
                                else
                                    std::cout << "Turi buti bent 1 pazymys..." << std::endl;
                            }
                        } 
                        else
                            std::cout << erroras << std::endl;
                    }
                    break;
                    }
                    else {
                        std::cin.ignore();
                        std::cin.clear();
                        std::cout << erroras << std::endl;}
                    
                    }
                    
                    new_line();
                    std::cout << "Dabar ivesk gauta egzamino pazymi " << std::endl;
                    int egz;
                    while(true){
                        std::string ivestis_string;
                        std::cin >> ivestis_string;
                        int ivestis;

                        if (is_digits(ivestis_string)==false){ // Tikrinu ar ten tik skaiciai, jei ne tai tiesiog i ivesti irasau netinkama skaiciu
                            ivestis=-1;
                        }
                        else
                        {
                            ivestis = std::stoi(ivestis_string); // Jei viskas ok string pavercia i int
                        }
                        

                        if (ivestis<0 or ivestis>10){ // Per mazas ar per didelis skaicius netinka
                            std::cout << erroras << std::endl;
                        }
                        else
                        {
                            egz=ivestis;
                            break;
                        }
                    }

                    double vid;
                    if (vid_pasirinkimas==1)
                        vid=vidurkis(pazymiai,sk);
                    else
                        vid=mediana(pazymiai,sk);
                    

                    A[stud_nr].SetGalutinis(1.0*(0.4*vid+0.6*egz));
                    std::cin.ignore();
                    std::cin.clear(); // Trinu visus cin, kad isvengti nesamoniu visokiu
                }
                else{
                    std::cout << erroras << std::endl;
                }
            }
            
            else{
                if (stud_nr==-1)
                    std::cout << "Irasyk duomenis bent apie 1 studenta!"<< std::endl;
                else{
                    spausdinimas(stud_nr,A,vid_pasirinkimas);
                    break;
                }       
            }
        }
    }
    else if (ivedimo_pasirinkimas==2)
    {
        std::string eilute,vardas,pavarde;
        std::ifstream in_file ("kursiokai.txt");
        if (in_file.good()){
            while(std::getline(in_file,eilute)){  // Nuskaito po visa eilute txt faile
                A.push_back(Studentas());
                std::istringstream in_line(eilute); // Skaitymas is eilutes

                in_line >> vardas >> pavarde;
                if(all_letters(vardas) and all_letters(pavarde)){
                    stud_nr++;
                    A[stud_nr].SetVardas(vardas);
                    A[stud_nr].SetPavarde(pavarde);

                    
                    A[stud_nr].SetVardas(convert_to_proper_format(A[stud_nr].GetVardas()));
                    A[stud_nr].SetPavarde(convert_to_proper_format(A[stud_nr].GetPavarde()));

                    int sk=0;
                    std::vector<int> pazymiai;
                    while(in_line>>temp){
                        if(is_digits(temp)){
                            int ivestis = std::stoi(temp);
                            if (ivestis>=0 and ivestis<=10){
                                pazymiai.push_back(int());
                                pazymiai[sk]=ivestis;
                                sk++;
                            }
                        }
                    }

                    in_line.end;

                    int egz = 0;
                    if (sk>0) // Cia nes gali buti, jog neives skaiciu visai ir tada gali iseit pazymiai[-1]
                        egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys

                    if (sk>1){
                        A[stud_nr].SetGalutinis(1.0*(0.4*vidurkis(pazymiai,sk-1)+0.6*egz));
                        A[stud_nr].SetGalutinis2(1.0*(0.4*mediana(pazymiai,sk-1)+0.6*egz));
                    }
                    else
                    {
                        A[stud_nr].SetGalutinis(1.0*(0.6*egz));
                        A[stud_nr].SetGalutinis2(1.0*(0.6*egz));
                    }
                }
            }
            if (stud_nr>-1)
                rikiavimas(A,stud_nr); // Ten rikiuoju o isrikiaves siunciu iskart i spausdinima
            else{
                new_line();
                std::cout << "Failas yra tuscias arba ivesti duomenys yra netinkami." << std::endl;
            }
        }
        else{
            new_line();
            std::cout << "Tokio failo nera." << std::endl;
        }
            
        
        in_file.end;
    }
    else if (ivedimo_pasirinkimas==3){
        new_line();
        std::cout << "Kiek zmoniu turetu but sugeneruota?\n1- 10\n2- 100\n3- 1000\n4- 10000\n5- 100000\n";
        int sk_pasirinkimas,pazymiu_sk=10; //pagal pazymiu_sk sprendzia kiek pazymiu kiekvienam generuoti
        int zmoniu_sk=10;
        while (true){
            int temp_nr;
            std::cin >> temp_nr;
            try {
                if (std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    throw "Turi ivesti skaiciu!";
                }
                else{
                    if (temp_nr>=1 and temp_nr<=5){
                        sk_pasirinkimas=temp_nr;
                        break;
                    }
                    else{
                        throw "Netinkamas skaicius.";
                    }    
                }
            } catch (const char* e){
                std::cout << e << std::endl;
            }
        }
        

        std::ofstream toFile ("kursiokai.txt");
        for (int i=1;i<sk_pasirinkimas;i++)
            zmoniu_sk=zmoniu_sk*10;


        for (int i=0; i<zmoniu_sk; i++){
            toFile << "Vardas" << i+1 << " Pavarde" << i+1;
            for (int j=0;j<=pazymiu_sk;j++)
                toFile << " " << range(mt);
            toFile << "\n";
        }
        toFile.close();

        ///----------------------------------

        std::string eilute,vardas,pavarde;
        std::ifstream in_file ("kursiokai.txt");
        std::ofstream kietas ("kieti.txt");
        std::ofstream vargsas ("vargsai.txt");
        auto startas = std::chrono::system_clock::now();
        while(std::getline(in_file,eilute)){  // Nuskaito po visa eilute txt faile
            A.push_back(Studentas());
            std::istringstream in_line(eilute); // Skaitymas is eilutes

            in_line >> vardas >> pavarde;
            stud_nr++;
            A[stud_nr].SetVardas(vardas);
            A[stud_nr].SetPavarde(pavarde);

            int sk=0;
            std::vector<int> pazymiai;
            while(in_line>>temp){
                if(is_digits(temp)){
                    int ivestis = std::stoi(temp);
                    if (ivestis>=0 and ivestis<=10){
                        pazymiai.push_back(int());
                        pazymiai[sk]=ivestis;
                        sk++;
                    }
                }
            }

            int egz = 0;
            if (sk>0) // Cia nes gali buti, jog neives skaiciu visai ir tada gali iseit pazymiai[-1]
                egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys

            if (sk>1){
                A[stud_nr].SetGalutinis(1.0*(0.4*vidurkis(pazymiai,sk-1)+0.6*egz));
                A[stud_nr].SetGalutinis2(1.0*(0.4*mediana(pazymiai,sk-1)+0.6*egz));
            }
            else
            {
                A[stud_nr].SetGalutinis(1.0*(0.6*egz));
                A[stud_nr].SetGalutinis2(1.0*(0.6*egz));
            }

        }
        auto pabaiga = std::chrono::system_clock::now();
        auto uztruko = std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
        std::cout << "Duomenu nuskaitymas uztruko - " << uztruko << " sec." << std::endl;

        startas = std::chrono::system_clock::now();
        rusiavimas(A);
        pabaiga = std::chrono::system_clock::now();
        uztruko = std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
        std::cout << "Studentu rusiavimas uztruko - " << uztruko << " sec." << std::endl;

        std::vector<Studentas>::size_type i = 0;
        while (i != vargsai.size()){
            vargsas << vargsai[i].GetVardas() << " " << vargsai[i].GetPavarde() << " " << vargsai[i].GetGalutinis() << " " << vargsai[i].GetGalutinis2() << std::endl;
            i++;
        }
        i = 0;
         while (i != A.size()){
            kietas << A[i].GetVardas() << " " << A[i].GetPavarde() << " " << A[i].GetGalutinis() << " " << A[i].GetGalutinis2() << std::endl;
            i++;
        }
        
        
        kietas.close();
        vargsas.close();
        in_file.close();

        std::cout << "Studentai surusiuoti i failus kieti.txt ir vargsai.txt" << std::endl;
    }
    

return 0;
}
