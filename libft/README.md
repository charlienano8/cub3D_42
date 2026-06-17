# libft

*This project has been created as part of the 42 curriculum by aborda.*

---

## Description

**Libft** est le tout premier projet du cursus 42. L'objectif est de recoder un ensemble de fonctions de la librairie standard C, puis de l'enrichir avec des fonctions supplémentaires utiles pour les projets suivants.

### Objectifs

- Recoder les fonctions standard de la libc
- Intégrer ft_printf et get_next_line comme extensions de la bibliothèque

### Contenu de la bibliothèque

#### Fonctions Libc

Recréation des fonctions standard : `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`, `ft_toupper`, `ft_tolower`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`

#### Fonctions additionnelles

`ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

#### Fonctions bonus (listes chaînées)

`ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

#### Fonctions personnelles

`ft_intlen`, `ft_longlen`, `ft_unsignedint_len`, `ft_putunsignedint_fd`, `ft_isspace`, `ft_is_valid_int`, `ft_atol`

#### ft_printf

Recréation de `printf` avec gestion des conversions : `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

#### get_next_line

Lecture ligne par ligne depuis un file descriptor, avec support multi-fd.

---

## Instructions

### Prérequis

- `cc`
- `make`

### Compilation

```bash
make
```

Cette commande génère la bibliothèque statique `libft.a`

### Utilisation

Pour utiliser libft dans un projet :

```c
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line_bonus.h"
```

```bash
# Compiler avec libft
cc -Wall -Wextra -Werror main.c -Ipath/to/libft/includes -Lpath/to/libft -lft
```

### Commandes Makefile

- `make` ou `make all` : compile la bibliothèque
- `make clean` : supprime les fichiers objets
- `make fclean` : supprime les fichiers objets et la bibliothèque
- `make re` : recompile entièrement le projet

---

## Resources

### Documentation et références

- [Manuel C (man pages)](https://man7.org/linux/man-pages/)
- Sujet officiel du projet : `en.subject.pdf`
- Norme 42 : `fr.norme.pdf`

### Utilisation de l'IA

Dans le cadre de ce projet, l'intelligence artificielle (Claude) a été utilisée comme **outil d'assistance pédagogique** en complément du **PEERLEARNING** :

- **Compréhension de concepts** : clarification de notions (pointeurs, allocation mémoire, listes chaînées)
- **Raisonnement** : aide à la réflexion sur l'architecture du code et la gestion des edge cases
- **Debugging** : assistance dans l'identification de bugs logiques

**Important** : L'IA n'a **jamais été utilisée pour générer du code complet**. L'ensemble du code a été écrit manuellement, avec l'IA servant uniquement de guide pédagogique pour comprendre les concepts et améliorer le raisonnement.

---

## Auteur

**Antoine Borda (aborda)** - École 42 Paris
