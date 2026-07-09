# cub3d

*This project has been created as part of the 42 curriculum by aborda and makui.*

---

## Description

**cub3D** is a 3D graphical game engine inspired by the world-famous 90's classic *Wolfenstein 3D*. The goal of this project is to explore the technique of **Raycasting** a mathematical geometry application that simulates a 3D perspective environment from a strictly 2D map grid.

### Objectifs

- BlaBla

### Features

**Real-time 3D Raycasting Rendering:** Dynamically projects walls with strict field-of-view (FOV) calculations.
**Texture Mapping:** Implements independent wall texture loading (North, South, East, West faces) via standard XPM files using the MiniLibX library.
**Smooth Movement & Interaction:** Supports fluid WSAD keyboard navigation, orientation rotation using the arrow keys.

---

## Instructions

### Prerequisites

Make sure you have the required graphical dependencies installed on your system (`X11` and `MiniLibX`).

### Cloner le projet

Le projet utilise **libft** en tant que submodule Git. Pour cloner correctement :

```bash
git clone --recursive <url_du_repo>
```

Ou si le repo est déjà cloné sans les submodules :

```bash
git submodule update --init --recursive
```

### Compilation

```bash
make
```

Cette commande genere l'executable `cub3d`.

### Utilisation

```bash
./cub3d
```

### Commandes Makefile

- `make` ou `make all` : compile le projet
- `make clean` : supprime les fichiers objets
- `make fclean` : supprime les fichiers objets et l'executable
- `make re` : recompile entierement le projet

---

## Resources

### Documentation et references

- Sujet officiel du projet : `en.subject.pdf`
- Norme 42 : `fr.norme.pdf`

### Utilisation de l'IA

Dans le cadre de ce projet, l'intelligence artificielle (Claude) a ete utilisee comme **outil d'assistance pedagogique** en complement du **PEERLEARNING** :

- **Comprehension de concepts** : clarification de notions (fork, pipe, dup2, signaux, file descriptors)
- **Raisonnement** : aide a la reflexion sur l'architecture du parser et de l'execution
- **Debugging** : assistance dans l'identification de bugs logiques et de fuites de FD

**Important** : L'IA n'a **jamais ete utilisee pour generer du code complet**. L'ensemble du code a ete ecrit manuellement, avec l'IA servant uniquement de guide pedagogique pour comprendre les concepts et ameliorer le raisonnement.

---

## Auteurs

**Antoine Borda (aborda)** & **Makui (makui)** - Ecole 42 Paris
