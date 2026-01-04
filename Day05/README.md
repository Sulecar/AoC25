# Day05

Prvi del naloge se osredotoča na preverjanje prisotnosti posameznih vrednosti znotraj podanih intervalov. Program se sprehodi skozi seznam vseh prebranih ID-jev in za vsakega posebej preveri, ali ustreza pogoju poljubnega razpona v tabeli območij. Da se izognemo večkratnemu štetju istega ID-ja, se iskanje za posamezno število ustavi takoj, ko je potrjena njegova pripadnost v vsaj enemu intervalu. Končni rezultat predstavlja skupno število vrednosti, ki so bile uspešno najdene znotraj definiranih meja.

V drugem delu program izračuna, koliko unikatnih števil skupaj pokrivajo vsa območja. Da se izogne dvojnemu štetju zaradi prekrivanja, območja najprej razvrsti po vrsti in jih nato v enem prehodu združi v neprekinjene bloke. Ko ugotovi, kje se nek sklop konča, izračuna njegovo dolžino in jo doda k skupnemu seštevku. Tako dobimo točno število vseh zajetih točk, ne glede na to, kolikokrat se posamezni intervali med seboj prekrijejo.
