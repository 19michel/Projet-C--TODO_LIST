#On commence par supprimer ce qui peut exister dans la mémoire
./todo del

echo -e "\e[1;34;47mLANCEMENT DES TESTS\e[0m"
echo -e "\n\n"

#On teste la fonction add
echo -e "\e[1;4;30mADD\e[0m"
./todo add
d=`date +%_d`; m=`date +%_m`; y=`date +%_y`; H=`date +%_H`; M=`date +%_M`; S=`date +%_S`; m="${m// }"; d="${d// }"; H="${H// }"; M="${M// }"; S="${S// }"
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 0. Achievement: 0%\n" > add.txt
./todo print >> todo.txt
diff add.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "\e[0;32mSUCCES\e[0m"
else
    echo -e "\e[0;31mFAIL\e[0m"
fi
rm add.txt
rm todo.txt
echo -e "\n\n"

#On teste la fonction change
echo -e "\e[1;4;30;40mCHANGE\e[0;m"

#D'abord avec la priorité
echo -e "      \e[4mPriority\e[0m"
./todo change --id 0 --priority 5
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 0%\n" > change.txt
./todo print >> todo.txt
diff change.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm change.txt
rm todo.txt
echo -e "\n"

#Puis avec l'avancement
echo -e "      \e[4mAchievement\e[0m"
./todo change --id 0 --achiev 47
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n" > change.txt
./todo print >> todo.txt
diff change.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm change.txt
rm todo.txt
echo -e "\n\n"

#On teste la fonction comments
echo -e "\e[1;4;30mCOMMENTS\e[0m"
./todo comments --id 0 --comments "Commentaire test"
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n" > comments.txt
./todo print >> todo.txt
diff comments.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "\e[0;32mSUCCES\e[0m"
else
    echo -e "\e[0;31mFAIL\e[0m"
fi
rm comments.txt
rm todo.txt
echo -e "\n\n"

#On teste le fonctionnement des sous-tâches
echo -e "\e[1;4;30mSUBTASK\e[0m"

#L'ajout...
echo -e "      \e[4mAjout\e[0m"
./todo add --title "Sous-tache" --description "Une description" --priority 2 --subtask "No title"
dST=`date +%_d`; mST=`date +%_m`; yST=`date +%_y`; HST=`date +%_H`; MST=`date +%_M`; SST=`date +%_S`; mST="${mST// }"; dST="${dST// }"; HST="${HST// }"; MST="${MST// }"; SST="${SST// }"
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n1 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 2. Achievement: 0%\n\n" > subtask.txt
./todo print >> todo.txt
diff subtask.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm subtask.txt
rm todo.txt
echo -e "\n"

echo -e "      \e[4mChange\e[0m"

#... le changement de priorité...
echo "            Priority"
./todo change --id 1 --priority 1
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n1 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 0%\n\n" > change.txt
./todo print >> todo.txt
diff change.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "            \e[0;32mSUCCES\e[0m"
else
    echo -e "            \e[0;31mFAIL\e[0m"
fi
rm change.txt
rm todo.txt
echo -e "\n"

#... le changement d'avancement...
echo "            Achievement"
./todo change --id 1 --achiev 83
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n1 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n\n" > change.txt
./todo print >> todo.txt
diff change.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "            \e[0;32mSUCCES\e[0m"
else
    echo -e "            \e[0;31mFAIL\e[0m"
fi
rm change.txt
rm todo.txt
echo -e "\n"

#... et l'ajout de commentaires
echo -e "      \e[4mComments\e[0m"
./todo comments --id 1 --comments "C'est une sous-tache"
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n1 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n  Comments:\n      C'est une sous-tache\n\n" > comments.txt
./todo print >> todo.txt
diff comments.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm comments.txt
rm todo.txt
echo -e "\n\n"

#Puis, on s'intéresse à la fermeture des tâches avec la fonction close
echo -e "\e[1;4;30mCLOSE\e[0m"
./todo close --id 0
dc=`date +%_d`; mc=`date +%_m`; yc=`date +%_y`; Hc=`date +%_H`; Mc=`date +%_M`; Sc=`date +%_S`; mc="${mc// }"; dc="${dc// }"; Hc="${Hc// }"; Mc="${Mc// }"; Sc="${Sc// }"
#On affiche plus rien si on ne précise rien
echo -e "      \e[4mAffichage taches en cours\e[0m"
echo -e "\n" > close.txt
./todo print >> todo.txt
diff close.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm close.txt
rm todo.txt
echo -e "\n"

#Ou alors on affiche la tâche si on précise une priorité de -1 correspondant aux tâches fermées
echo -e "      \e[4mAffichage taches terminees\e[0m"
echo -e "\n0 / No title: No description -> close, opened on $d/$m/20$y $H:$M:$S and closed on $dc/$mc/20$yc $Hc:$Mc:$Sc. Priority: -1. Achievement: 100%\n  Comments:\n      Commentaire test\n  TASKS:\n1 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n  Comments:\n      C'est une sous-tache\n\n" > close.txt
./todo print --priority -1 >> todo.txt
diff close.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    echo -e "      \e[0;31mFAIL\e[0m"
fi
rm close.txt
rm todo.txt
echo -e "\n\n"

#Finalement, on vérifie la fonction del
echo -e "\e[1;4;30mDELETE\e[0m"
./todo del
echo -e "\n" > del.txt
./todo print >> todo.txt
diff del.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "\e[0;32mSUCCES\e[0m"
else
    echo -e "\e[0;31mFAIL\e[0m"
fi
rm del.txt
rm todo.txt
echo -e "\n"