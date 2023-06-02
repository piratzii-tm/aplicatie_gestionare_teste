# Aplicație gestionare teste 

Această aplicație a fost concepută pentru cursul Proiect Programare din cadrul Universității de Vest Timișoara. Aplicația este împărțită în două părți:

- App1 - partea profesorului 
- App2 - partea studentului 

Ambele aplicații au fost concepute pentru a fi executate din linia de comanda.

### App1 - partea profesorului 

App1 se folosește de clasele **Profesor**, **Test** și **Exercițiu**. Relațiile între clase sunt:

- *Compoziție* între **Test** și **Exercțiu**
- *Dependeță* între **Profesor** și **Test**

Pentru fiecare dintre clase s-a folosit supraîncărcarea operatorilor de citire **>>** și scriere **<<**

Comenzile ce pot fi scrise în linia de comandă sunt:

- `./App1.exe logare '<nume_profesor>'` 
    Comanda este folosită de către profesor pentru a se loga, restul comenzilor neputând fi executate dacă profesorul nu se loghează.<br><br>
- `./App1.exe vizualizare_profil`
    Afișează profilul profesorului care este logat la momentul respectiv. Profilul constă în afișarea numelui, numărului de teste create de profesor și afișarea fiecărui test în parte (fără statistici).<br><br>
- `./App1.exe vizualizare_statistici <id_test>`
    Afișează o statistică a testului respectiv, profesorului putând vizualiza numărului studenților care au primit o anumită notă. <br><br>
- `./App1.exe creare_test <id_test> <nr_exercitii>` 
    Se pornește o sesiune de creare test. Această sesiune nu permite executarea altor comezi decât cele de adăugare întrebare până când numărul întrebărilor adăugate nu este egal cu cel al întrebărilor totale.
- `./App1.exe adaugare_intrebare <enunt> <raspuns1> <raspuns2> <raspuns3> <raspuns4> <a/b/c/d>`
    Comandă folosită pentru a adauga o întrebare la testul pe care îl creem în sesiunea actuală. <br><br>
- `./App1.exe modificare_test <id_test>`
    Se pornește o sesiune de modificare test. Acestă comandă este necesară pentru specificarea testului pe care dorim să îl modificăm.
- `./App1.exe modificare_exercitiu <nr_exercitiu>` 
    După specificarea testului pe care dorim să îl modificăm ne folosim de această comandă pentru a specifica ce exercițiu dorim să modificăm.
- `./App1.exe enunt <noul_enunt>`
    Modificarea enuntului exercițiului
- `./App1.exe raspuns <litera_raspunusului> '<noul_rapuns>'`
    Înlocuirea răspunsului de la litera specificată cu un nou răspuns.
- `./App1.exe varianta_corecta <litera_raspuns_corect>`
    Modificarea variantei corecte de răspuns.
- `./App1.exe vizualizare_varianta_corecta`
    Afișează varianta curentă a testului.
- `./App1.exe stop_modificare_exercitiu`
- `./App1.exe stop_modificare_test`
<br><br>
- `./App1.exe delogare`

### App2 - partea elevului 

App1 se folosește de clasa **Student**, **Test** și **Exercițiu**. Relațiile între clase sunt:

- *Compoziție* între **Test** și **Exercțiu**
- *Agregare* între **Student** și **Test**

Comenzile ce pot fi scrise în linia de comandă sunt:

- `./App2.exe logare '<nume_student>'` 
    Comanda este folosită de către student pentru a se loga, restul comenzilor neputând fi executate dacă studentul nu se loghează.<br><br>
- `./App1.exe deschide_test <id_test>`
    Când accesăm această comandă, testul specificat, daca există va fi deschis
- `./App1.exe raspuns_intrebare <raspuns>`
    Când accesăm această comandă, dacă răspunsul este unul valid, se va trece la următoarea întrebare(răspunsurile sunt salvate doar la finalizarea testului) 
- `./App1.exe delogare`
    Comanda folosita pentru a de deloga
    
Cazuri speciale:
    -Dacă un student încearcă să deschidă un test, dar acesta nu este logat, nu i se va permite
    -Dacă un student încearcă să răspundă la o întrebare, dar acesta nu este logat sau nu este pornit nici un test, nu i se va permite
    -Dacă un student pornește un test înainte să îl fi finalizat pe cel curent, toate răspunsurile la testului vechi vor fi șterse
    -Dacă răspunsul la întrebare nu este a, b, c sau d, nu se va trece la următoarea întrebare, iar studentul va fi atenționat
