# Options de compilation
CFLAGS = -Wall -ansi -pedantic

# Commande de compilation
CC = gcc

# Tous les exécutables à créer
EXERCICES = exercice1 exercice2 exercice3 exercice4

# Créer tous les exécutables
all: $(EXERCICES)

# Règle générique pour créer un exécutable
%: %.c
	$(CC) $(CFLAGS) $< -o $@

# Nettoyer les fichiers générés
clean:
	rm -f $(EXERCICES)
