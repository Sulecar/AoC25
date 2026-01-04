# Day01
V prvem delu koda simulira premikanje po številčnici (0–99), kjer geslo predstavlja število rotacij, ki se zaključijo točno na ničli. Logika temelji na izračunu končnega položaja kazalca po vsakem ukazu, pri čemer se števec poveča le, če se vrtenje ustavi na oznaki 0.

### Prvi del (razlaga kode):
Iz vhodnih podatkov z uporabo substr in stoi razberemo smer rotacije (char) in število korakov (int). Namesto simulacije vsakega klika izračunamo le končni položaj s pomočjo modula: pri desni smeri korake prištejemo, pri levi pa odštejemo, pri čemer pazimo na popravek negativnih vrednosti. Po vsaki opravljeni rotaciji preverimo, ali je trenutna pozicija enaka 0, in v tem primeru povečamo spremenljivko geslo1.

## Drugi del:
V drugem delu koda namesto končnega cilja spremlja vsak posamezen premik za eno enoto. S sprotnim preverjanjem položaja znotraj zanke program zazna vsak prehod čez ničlo, tudi če se rotacija nadaljuje ali kazalec naredi več polnih krogov.

### Drugi del (razlaga kode):
Obdelava vhodnih podatkov ostane enaka, spremeni pa se način premikanja kazalca. Uporabimo zanko for, ki se izvede tolikokrat, kolikor je korakov v navodilu, in kazalec premika za eno enoto naenkrat. Znotraj te zanke po vsakem posameznem kliku takoj preverimo vrednost pozicije; če ta doseže 0, povečamo spremenljivko geslo2.