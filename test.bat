echo -e "\e[1;34;47mLANCEMENT DES TESTS\e[0m"
echo -e "\n\n"

#On teste la fonction add
echo -e "\e[1;4;30mADD\e[0m"

#Sans paramètres
echo -e "      \e[4mSans parametres\e[0m"
./todo --file "test.todo" add
d=`date +%-d`; m=`date +%-m`; y=`date +%-y`; H=`date +%-H`; M=`date +%-M`; S=`date +%-S`
dd=`date --date '1 second ago' +%-d`; mm=`date --date '1 second ago' +%-m`; yy=`date --date '1 second ago' +%-y`; HH=`date --date '1 second ago' +%-H`; MM=`date --date '1 second ago' +%-M`; SS=`date --date '1 second ago' +%-S`
echo -e "\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 0. Achievement: 0%\n\n" > add.txt
./todo --file "test.todo" print >> todo.txt
diff add.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    rm add.txt
    echo -e "\n0 / No title: No description -> open, opened on $dd/$mm/20$yy $HH:$MM:$SS. Priority: 0. Achievement: 0%\n\n" > add.txt
    diff add.txt todo.txt
    if [ $? -eq 0 ]
    then
        echo -e "      \e[0;32mSUCCES\e[0m"
        d=$dd; m=$mm; y=$yy; H=$HH; M=$MM; S=$SS
    else
        echo -e "      \e[0;31mFAIL\e[0m"
    fi
fi
rm add.txt
rm todo.txt
echo -e "\n"

#Avec paramètres
echo -e "      \e[4mAvec parametres\e[0m"
./todo --file "test.todo" add --title "titre" --description "description" --priority 252
d2=`date +%-d`; m2=`date +%-m`; y2=`date +%-y`; H2=`date +%-H`; M2=`date +%-M`; S2=`date +%-S`
dd2=`date --date '1 second ago' +%-d`; mm2=`date --date '1 second ago' +%-m`; yy2=`date --date '1 second ago' +%-y`; HH2=`date --date '1 second ago' +%-H`; MM2=`date --date '1 second ago' +%-M`; SS2=`date --date '1 second ago' +%-S`
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 0. Achievement: 0%\n\n" > add.txt
./todo --file "test.todo" print >> todo.txt
diff add.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    rm add.txt
    echo -e "\n1 / titre: description -> open, opened on $dd2/$mm2/20$yy2 $HH2:$MM2:$SS2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 0. Achievement: 0%\n\n" > add.txt
    diff add.txt todo.txt
    if [ $? -eq 0 ]
    then
        echo -e "      \e[0;32mSUCCES\e[0m"
        d2=$dd2; m2=$mm2; y2=$yy2; H2=$HH2; M2=$MM2; S2=$SS2
    else
        echo -e "      \e[0;31mFAIL\e[0m"
    fi
fi
rm add.txt
rm todo.txt
echo -e "\n\n"

#On teste la fonction change
echo -e "\e[1;4;30;40mCHANGE\e[0;m"

#D'abord avec la priorité
echo -e "      \e[4mPriority\e[0m"
./todo --file "test.todo" change --id 0 --priority 5
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 0%\n\n" > change.txt
./todo --file "test.todo" print >> todo.txt
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
./todo --file "test.todo" change --id 0 --achiev 47
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n\n" > change.txt
./todo --file "test.todo" print >> todo.txt
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
./todo --file "test.todo" comments --id 0 --comments "Commentaire test"
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n\n" > comments.txt
./todo --file "test.todo" print >> todo.txt
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
echo -e "      \e[4mAjout avec le titre de la tache principale\e[0m"
./todo --file "test.todo" add --title "Sous-tache" --description "Une description" --priority 2 --maintask "No title"
dST=`date +%-d`; mST=`date +%-m`; yST=`date +%-y`; HST=`date +%-H`; MST=`date +%-M`; SST=`date +%-S`
ddST=`date --date '1 second ago' +%-d`; mmST=`date --date '1 second ago' +%-m`; yyST=`date --date '1 second ago' +%-y`; HHST=`date --date '1 second ago' +%-H`; MMST=`date --date '1 second ago' +%-M`; SSST=`date --date '1 second ago' +%-S`
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 2. Achievement: 0%\n\n\n" > subtask.txt
./todo --file "test.todo" print >> todo.txt
diff subtask.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    rm subtask.txt
    echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n2 / Sous-tache: Une description -> open, opened on $ddST/$mmST/20$yyST $HHST:$MMST:$SSST. Priority: 2. Achievement: 0%\n\n\n" > subtask.txt
    diff subtask.txt todo.txt
    if [ $? -eq 0 ]
    then
        echo -e "      \e[0;32mSUCCES\e[0m"
        dST=$ddST; mST=$mmST; yST=$yyST; HST=$HHST; MST=$MMST; SST=$SSST
    else
        echo -e "      \e[0;31mFAIL\e[0m"
    fi
fi
rm subtask.txt
rm todo.txt
echo -e "\n"

echo -e "      \e[4mAjout avec l'id de la tache principale\e[0m"
./todo --file "test.todo" add --title "Autre sous-tache" --description "Une autre description" --priority 5 --id 0
dST2=`date +%-d`; mST2=`date +%-m`; yST2=`date +%-y`; HST2=`date +%-H`; MST2=`date +%-M`; SST2=`date +%-S`
ddST2=`date --date '1 second ago' +%-d`; mmST2=`date --date '1 second ago' +%-m`; yyST2=`date --date '1 second ago' +%-y`; HHST2=`date --date '1 second ago' +%-H`; MMST2=`date --date '1 second ago' +%-M`; SSST2=`date --date '1 second ago' +%-S`
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 2. Achievement: 0%\n\n\n" > subtask.txt
./todo --file "test.todo" print >> todo.txt
diff subtask.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    rm subtask.txt
    echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $ddST2/$mmST2/20$yyST2 $HHST2:$MMST2:$SSST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 2. Achievement: 0%\n\n\n" > subtask.txt
    diff subtask.txt todo.txt
    if [ $? -eq 0 ]
    then
        echo -e "      \e[0;32mSUCCES\e[0m"
        dST2=$ddST2; mST2=$mmST2; yST2=$yyST2; HST2=$HHST2; MST2=$MMST2; SST2=$SSST2
    else
        echo -e "      \e[0;31mFAIL\e[0m"
    fi
fi
rm subtask.txt
rm todo.txt
echo -e "\n"

echo -e "      \e[4mChange\e[0m"

#... le changement de priorité...
echo "            Priority"
./todo --file "test.todo" change --id 2 --priority 1
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 0%\n\n\n" > change.txt
./todo --file "test.todo" print >> todo.txt
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
./todo --file "test.todo" change --id 2 --achiev 83
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n\n\n" > change.txt
./todo --file "test.todo" print >> todo.txt
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
./todo --file "test.todo" comments --id 2 --comments "C'est une sous-tache"
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> open, opened on $d/$m/20$y $H:$M:$S. Priority: 5. Achievement: 47%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n  Comments:\n      C'est une sous-tache\n\n\n" > comments.txt
./todo --file "test.todo" print >> todo.txt
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
./todo --file "test.todo" close --id 0
dc=`date +%-d`; mc=`date +%-m`; yc=`date +%-y`; Hc=`date +%-H`; Mc=`date +%-M`; Sc=`date +%-S`
ddc=`date --date '1 second ago' +%-d`; mmc=`date --date '1 second ago' +%-m`; yyc=`date --date '1 second ago' +%-y`; HHc=`date --date '1 second ago' +%-H`; MMc=`date --date '1 second ago' +%-M`; SSc=`date --date '1 second ago' +%-S`
#On affiche plus la tache fermée si on ne précise rien
echo -e "      \e[4mAffichage taches en cours\e[0m"
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n" > close.txt
./todo --file "test.todo" print >> todo.txt
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
echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> close, opened on $d/$m/20$y $H:$M:$S and closed on $dc/$mc/20$yc $Hc:$Mc:$Sc. Priority: -1. Achievement: 100%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n  Comments:\n      C'est une sous-tache\n\n\n" > close.txt
./todo --file "test.todo" print --priority -1 >> todo.txt
diff close.txt todo.txt
if [ $? -eq 0 ]
then
    echo -e "      \e[0;32mSUCCES\e[0m"
else
    rm close.txt
    echo -e "\n1 / titre: description -> open, opened on $d2/$m2/20$y2 $H2:$M2:$S2. Priority: 10. Achievement: 0%\n\n0 / No title: No description -> close, opened on $d/$m/20$y $H:$M:$S and closed on $ddc/$mmc/20$yyc $HHc:$MMc:$SSc. Priority: -1. Achievement: 100%\n  Comments:\n      Commentaire test\n  TASKS:\n3 / Autre sous-tache: Une autre description -> open, opened on $dST2/$mST2/20$yST2 $HST2:$MST2:$SST2. Priority: 5. Achievement: 0%\n2 / Sous-tache: Une description -> open, opened on $dST/$mST/20$yST $HST:$MST:$SST. Priority: 1. Achievement: 83%\n  Comments:\n      C'est une sous-tache\n\n\n" > close.txt
    diff close.txt todo.txt
    if [ $? -eq 0 ]
    then
        echo -e "      \e[0;32mSUCCES\e[0m"
        dc=$ddc; mc=$mmc; yc=$yyc; Hc=$HHc; Mc=$MMc; Sc=$SSc
    else
        echo -e "      \e[0;31mFAIL\e[0m"
    fi
fi
rm close.txt
rm todo.txt
echo -e "\n\n"

#Finalement, on vérifie la fonction del
echo -e "\e[1;4;30mDELETE\e[0m"
./todo --file "test.todo" del
echo -e "\n" > del.txt
./todo --file "test.todo" print >> todo.txt
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