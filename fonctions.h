#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <tuple>
#include "task.h"
#include "todo.h"
using namespace std;

#pragma once

vector<string> c_t_str (int argc, char**  argv);
/* convertir un char** en vector<string> */

vector<string> extract (string file);
/* lire un fichier et renvoyer son contenu dans un vector<string> */

void write (string file, const vector<string> & v_str, int i, int nb);
/* ecrire dans un fichier nb éléments d'un vector<string> à partir de l'indice i */

To_Do main_no_write(const vector<string> & v_str);
/* effectue les mêmes actions que le main, c'est-à-dire interpréter une ligne de commande sous la forme d'un vector<string>, mais n'enregistre aucune de ces actions.
Cette fonction permet de lire les actions enregistrées sans les enregistrer à nouveau */

vector<string> main_add (const vector<string> & v_str, To_Do & list, int & i) ;
/* interprete add dans le ligne de commande.
La référence à l'indice i permet de parcourir le v_str qui correspond au argv de la ligne de commande
Celle à la to-do liste permet de construire au fur et à mesure de la lecture de la ligne de commande la to-do liste*/

vector<string> main_close(const vector<string> & v_str, To_Do & list, int & i);
/* interprete close dans le ligne de commande */ 

void main_add_dated (const vector<string> & v_str, To_Do & list, int & i) ;
/* interprete add dans le fichier sauvegardé.
A la différence de lors de la lecture de la ligne de commande, il n'y a pas besoin de prendre la date de l'ordinateur et de l'enregistrer.
Il suffit de lire la date déjà stockée dans le fichier*/

void main_close_dated (const vector<string> & v_str, To_Do & list, int & i);
/* interprete close dans le fichier sauvegardé */

void main_change (const vector<string> & v_str, To_Do & list, int & i);
/* interprete change dans le ligne de commande et dans le fichier enregistré */

void main_comments (const vector<string> & v_str, To_Do & list, int & i);
/* interprete comments dans le ligne de commande et dans le fichier enregistré */

void main_del (string file);
/* interprete del dans la ligne de commande */

void main_man (const vector<string> & v_str, int & i);
/* interprete help et renvoie le manuel */