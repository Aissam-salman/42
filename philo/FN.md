# Function 

printf, malloc, free, write,
usleep, 
---
*memset*
Remplir une zone mémoire avec un octet donné  

```c
#include <string.h>

void *memset (void *s, int c, size_t n);
```

DESCRIPTION
La fonction memset() remplit les n premiers octets de la zone mémoire pointée par s avec l'octet c.  
VALEUR RENVOYÉE
La fonction memset() renvoie un pointeur sur la zone mémoire s.

---

*gettimeofday*
Lire/écrire l'heure actuelle  
```c
#include <sys/time.h>
int gettimeofday(struct timeval *tv, struct timezone *tz);
```

 L'argument tv est une structure timeval
```c
struct timeval {
    time_t      tv_sec;  /* secondes */
    suseconds_t tv_usec; /* microsecondes */
};
```
argument tz est une structure timezone composée ainsi :
L'utilisation de la structure timezone est obsolète ;

```c
struct timezone {
    int tz_minuteswest; /* minutes à l'ouest de Greenwich  */
    int tz_dsttime;     /* type de changement horaire      */
};
```
Si soit tv soit tz est NULL, la structure correspondante n'est ni remplie ni renvoyée.

VALEUR RENVOYÉE
gettimeofday() renvoient 0 s'ils réussissent, ou -1 s'ils échouent, auquel cas errno est renseignée en conséquence.

---

*pthread_create*
Créer un nouveau thread

```c
#include <pthread.h>

int pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg);
```
DESCRIPTION
pthread_create() crée un nouveau thread s'exécutant simultanément avec le thread appelant.
Le nouveau thread exécute la fonction start_routine en lui passant arg comme premier argument. 
Le nouveau thread s'achève soit explicitement en appelant pthread_exit(3), ou implicitement 
lorsque la fonction start_routine s'achève. 
Ce dernier cas est équivalent à appeler pthread_exit(3) avec la valeur renvoyée par start_routine comme code de sortie.

L'argument attr indique les attributs du nouveau thread. Voir pthread_attr_init(3) pour une liste complète des attributs. 
L'argument attr peut être NULL, auquel cas, les attributs par défaut sont utilisés : 
le thread créé est joignable (non détaché) et utilise la politique d'ordonnancement normale (pas temps-réel).  

VALEUR RENVOYÉE
En cas de succès, l'identifiant du nouveau thread est stocké à l'emplacement mémoire pointé par 
l'argument thread, et 0 est renvoyé. En cas d'erreur, un code d'erreur non nul est renvoyé.  

ERREURS

EAGAIN
    Pas assez de ressources système pour créer un processus pour le nouveau thread. 
EAGAIN
    Il y a déjà plus de PTHREAD_THREADS_MAX threads actifs. 



*pthread_detach*
Place un thread en cours d'éxécution dans l'état détaché
```c
#include <pthread.h>

int pthread_detach(pthread_t th);  
```

DESCRIPTION
pthread_detach() place le thread th dans l'état détaché. 
Cela garantit que les ressources mémoire consommées par th seront immédiatement libérées lorsque l'exécution de th s'achèvera. 
Cependant, cela empêche les autres threads de se synchroniser sur la mort de th en utilisant pthread_join(3).

Un thread peut être créé initialement dans l'état détaché, en utilisant l'attribut detachstate dans l'appel de pthread_create(3). Par opposition, pthread_detach() ne s'applique qu'aux threads créés dans l'état joignable, et nécessitant d'être mis dans l'état détaché plus tard.

Dès que pthread_detach() rend la main, tout appel ultérieur à pthread_join(3) sur th échouera. Si un autre thread est déjà en attente sur le thread th lorsque pthread_detach() est appelée, pthread_detach() ne fait rien, et laisse th dans l'état joignable.  

VALEUR RENVOYÉE
En cas de succès, 0 est renvoyé. En cas d'erreur, un code d'erreur non nul est renvoyé.  

ERREURS
ESRCH
    Aucun thread ne correspond à celui indiqué par th. 
EINVAL
    Le thread th est déjà dans l'état détaché.

*pthread_join*
Attendre la fin d'un autre thread
```c
#include <pthread.h>

int pthread_join(pthread_t th, void **thread_return);
```
DESCRIPTION
pthread_join() suspend l'exécution du thread appelant jusqu'à ce que le thread identifié par th achève son exécution, soit en appelant pthread_exit(3) soit après avoir été annulé.

Si thread_return ne vaut pas NULL, la valeur renvoyée par th y sera enregistrée. Cette valeur sera soit l'argument passé à pthread_exit(3), soit PTHREAD_CANCELED si le thread th a été annulé.

Le thread rejoint th doit être dans l'état joignable : il ne doit pas avoir été détaché par pthread_detach(3) ou par l'attribut PTHREAD_CREATE_DETACHED lors de sa création par pthread_create(3).

Quand l'exécution d'un thread joignable s'achève, ses ressources mémoire (descripteur de thread et pile) ne sont pas désallouées jusqu'à ce qu'un autre thread le joigne en utilisant pthread_join(). Aussi, pthread_join() doit être appelée une fois pour chaque thread joignable pour éviter des fuites de mémoire.

Au plus un seul thread peut attendre la mort d'un thread donné. Appeler pthread_join() sur un thread th dont un autre thread attend déjà la fin renvoie une erreur.  

ANNULATION
pthread_join est un point d'annulation. Si un thread est annulé alors qu'il est suspendu dans pthread_join(), l'exécution du thread reprend immédiatement et l'annulation est réalisée sans attendre la fin du thread th. Si l'annulation intervient durant pthread_join(), le thread th demeure non joint.  

VALEUR RENVOYÉE
En cas de succès, le code renvoyé par th est enregistré à l'emplacement pointé par thread_return, et 0 est renvoyé. En cas d'erreur, un code d'erreur non nul est renvoyé.  

ERREURS

ESRCH
    Aucun thread correspondant à th n'a pu être trouvé. 
EINVAL
    Le thread th a été détaché. 
EINVAL
    Un autre thread attend déjà la mort de th. 
EDEADLK
    L'argument th représente le thread appelant. 




pthread_mutex_init
pthread_mutex_destroy
pthread_mutex_lock
pthread_mutex_unlock

Opérations sur les mutex  
Un mutex est un objet d'exclusion mutuelle (MUTual EXclusion), et est très pratique pour protéger des données partagées de modifications concurrentes et pour implémenter des sections critiques.
Un mutex peut être dans deux états : déverrouillé (pris par aucun thread) ou verrouillé (appartenant à un thread)
Un mutex ne peut être pris que par un seul thread à la fois.
Un thread qui tente de verrouiller un mutex déjà verrouillé est suspendu jusqu'à ce que le mutex soit déverrouillé.


