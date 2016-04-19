#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

int main(int argc, char *argv[]){
 if(SDL_Init(SDL_INIT_VIDEO)){// SDL_INIT_VIDEO n'est pas une fonction mais une variable.
  fprintf(stderr, "Error SDL : %s\n", SDL_GetError());
 }
 //Créer la surface principale(Fenetre !!!!)
 SDL_Surface *fenetre = NULL;
 fenetre = SDL_SetVideoMode(500,500,32,SDL_HWSURFACE);//SDL_HWSURFACE: memoire de la carte graphique
 //Créer et stocker des couleurs
 Uint32 red,green, blue,couleurCapeDuPersonnage;
 couleurCapeDuPersonnage=SDL_MapRGB(fenetre->format,128,0,0);
 red = SDL_MapRGB(fenetre->format,255,0,0);
 green = SDL_MapRGB(fenetre->format,0,255,0);
 blue = SDL_MapRGB(fenetre->format,0,0,255);
 SDL_FillRect(fenetre,NULL,couleurCapeDuPersonnage);
 SDL_Flip(fenetre);// Actualiser la fenêtre
 //Créer une nouvelle fenêtre
 SDL_Surface *carreVert;
 carreVert = SDL_CreateRGBSurface(SDL_HWSURFACE,50,50,32,0,0,0,0);
 SDL_FillRect(carreVert,NULL,green);
 SDL_Rect carreVertPosition;
 carreVertPosition.x = 0;
 carreVertPosition.y = 0;
 SDL_BlitSurface(carreVert,NULL,fenetre,&carreVertPosition);
 SDL_Flip(fenetre);// Actualiser la fenêtre
 //Créer une nouvelle fenêtre
 SDL_Surface *carreBleu;
 carreBleu = SDL_CreateRGBSurface(SDL_HWSURFACE,50,50,32,0,0,0,0);
 SDL_FillRect(carreBleu,NULL,blue);
 SDL_Rect carreBleuPosition;
 carreBleuPosition.x = 450;
 carreBleuPosition.y = 450;
 SDL_BlitSurface(carreBleu,NULL,fenetre,&carreBleuPosition);
 SDL_Flip(fenetre);// Actualiser la fenêtre
 //Créer une nouvelle fenêtre
 SDL_Surface *carreMelange1;
 carreMelange1 = SDL_CreateRGBSurface(SDL_HWSURFACE,50,50,32,0,0,0,0);
 SDL_FillRect(carreMelange1,NULL,green-50);
 SDL_Rect carreMelangePosition;
 carreMelangePosition.x = 450;
 carreMelangePosition.y = 0;
 SDL_BlitSurface(carreMelange1,NULL,fenetre,&carreMelangePosition);
 SDL_Flip(fenetre);//Actualiser la fenêtre.
 //Créer une nouvelle fenêtre
 SDL_Surface *carreMelange2;
 carreMelange2 = SDL_CreateRGBSurface(SDL_HWSURFACE,50,50,32,0,0,0,0);
 SDL_FillRect(carreMelange2,NULL,(blue-150)/2);
 SDL_Rect carreMelangePositions;
 carreMelangePositions.x = 0;
 carreMelangePositions.y = 450;
 SDL_BlitSurface(carreMelange2,NULL,fenetre,&carreMelangePositions);
 SDL_Flip(fenetre);
 //Créer une nouvelle fenêtre
 SDL_Surface *carreMilieu;
 carreMilieu = SDL_CreateRGBSurface(SDL_HWSURFACE,50,50,32,0,0,0,0);
 SDL_FillRect(carreMilieu,NULL,red-125);
 SDL_Rect carreMilieuPosition;
 carreMilieuPosition.x = 150;
 carreMilieuPosition.y = 100;
 SDL_BlitSurface(carreMilieu,NULL,fenetre,&carreMilieuPosition);
 SDL_Flip(fenetre);
 //Boucle infini
 while(1){// ou for(;;)
   SDL_Event event;
   SDL_WaitEvent(&event);
   if(event.type == SDL_QUIT){break;}
}
 //Libérer la mémoire
 SDL_FreeSurface(fenetre);
   SDL_Quit();
  return 0;
}