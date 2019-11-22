#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include<vector>

using namespace std;

string melangerLettres(string mot)
{
    string melange;
    int position(0);

    // Tant que nous n'avons pas extrait toutes les lettres du mot
    while (mot.size() != 0)
    {
        // On choisit un numéro de lettre au hasard dans le mot
        position = rand() % mot.size();
        // On ajoute la lettre dans le mot mélangé
        melange += mot[position];
        // On retire cette lettre du mot mystère pour ne pas la prendre une 2e fois
        mot.erase(position, 1);
    }

    // On renvoie le mot mélangé
    return melange;
}

int main()
{
    string motMystere, motMelange, motUtilisateur;

    // Initialisation des nombres aléatoires
    srand(time(0));


    // 1 : On demande à saisir un mot
    cout << "Saisissez un mot" << endl;
    cin >> motMystere;

    // 2 : On récupère le mot avec les lettre mélangées dans motMelange
    motMelange = melangerLettres(motMystere);

    // 3 : On demande à l'utilisateur quel est le mot mystère
    // demmande de nouvel partie et calcul du score

    char nouvPartie;
    int score,i=0,j,nbrePartie=0,total=0;
    int results[nbrePartie];
    do{
        do{
            i++;
            cout << endl << "Quel est ce mot ? " << motMelange << endl;
            cin >> motUtilisateur;
            if(motMystere!=motUtilisateur){
                cout << "Ce n'est pas le mot !" << endl;
            }
            // On recommence tant qu'il n'a pas trouvé
            if (motUtilisateur == motMystere)
            {
                cout << "Bravo !" << endl;
                results[i]=1;
            }
            else
            {
                cout << "Ce n'est pas le mot ! le mot est: " << motMystere << endl;
                results[i]=0;
            }
            cout << "entrez n si vous voullez quitter et o pour une nouvelle partie: " << endl;
            cin >> nouvPartie;
        }while(i!=5 && motUtilisateur != motMystere);

        if(nouvPartie=='n'){
            for(j=0;j<nbrePartie;j++){
                total=results[j]+total;
            }
            score=total/nbrePartie;
        }
        else if(nouvPartie=='o'){
            nbrePartie++;
        }
            do{
        do{
            i++;
            cout << endl << "Quel est ce mot ? " << motMelange << endl;
            cin >> motUtilisateur;
            if(motMystere!=motUtilisateur){
                cout << "Ce n'est pas le mot !" << endl;
            }
            // On recommence tant qu'il n'a pas trouvé
            if (motUtilisateur == motMystere)
            {
                cout << "Bravo !" << endl;
                results[i]=1;
            }
            else
            {
                cout << "Ce n'est pas le mot ! le mot est: " << motMystere << endl;
                results[i]=0;
            }
            cout << "entrez n si vous voullez quitter et o pour une nouvelle partie: " << endl;
            cin >> nouvPartie;
        }while(i!=5 && motUtilisateur != motMystere);



    }while(nouvPartie=='n' && nouvPartie!='o');

    cout << "vous avez joue : " << nbrePartie << " parties et vous avez realiser un score de : " << total << "sur : " << nbrePartie << endl;
    cout << "votre score est : " << score << endl;
    return 0;
}
