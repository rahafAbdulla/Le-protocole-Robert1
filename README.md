# X21I020 - Algorithmique et Structures de données 1 - Projet

Projet de:
LEFAIX Alexandre
ABDULA Rahaf

Simulation de la transmission de contacts entre utilisateur d'une application, tout en permettant la confidentialité des utilisateurs grâce au protocole Robert.

## Ligne de commande pour la compilation :

### Compilation de l'application principale

Depuis Projet_ASD1/

```bash
g++ application_principale.cpp src/memoire_centrale.cpp src/contact_utilisateur.cpp src/pseudo_utilisateur.cpp src/date.cpp -o application_principale.exe
```

### Compilation des jeux de tests

Depuis Projet_ASD1/src/tests/

- Tests preliminaire.cpp :

```bash
g++ tests_preliminaire.cpp ../src/preliminaire.cpp -o tests_preliminaire.exe
```

- Tests date.cpp :

```bash
g++ tests_date.cpp ../src/date.cpp -o tests_date.exe
```

- Tests pseudo_utilisateur.cpp

```bash
g++ tests_pseudo_utilisateur.cpp ../src/pseudo_utilisateur.cpp -o tests_pseudo_utilisateur.exe
```

- Tests contact_utilisateur.cpp

```bash
g++ tests_contact_utilisateur.cpp ../src/contact_utilisateur.cpp ../src/pseudo_utilisateur.cpp ../src/date.cpp -o tests_contact_utilisateur.exe
```

- Tests memoire_centrale.cpp

```bash
g++ tests_memoire_centrale.cpp ../src/memoire_centrale.cpp ../src/contact_utilisateur.cpp ../src/pseudo_utilisateur.cpp ../src/date.cpp -o tests_memoire_centrale.exe
```
