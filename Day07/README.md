# Day07

### 1. Del:

Prvi del kode se osredotoča na prepoznavanje unikatnih vozlišč, kjer se pot dejansko razveja. Algoritem uporablja funkcijo za sledenje žarku, ki se premika navpično navzdol, dokler ne naleti na znak za razcep. Ob srečanju z razcepom se pot razdeli v dve novi smeri, hkrati pa program z uporabo matrike obiskanih točk prepreči večkratno štetje istega vozlišča. Končni rezultat predstavlja skupno število vseh odkritih unikatnih razcepnih točk na poti od začetka do dna matrike.

### 2. Del:

Drugi del rešuje problem s pomočjo dinamičnega programiranja za izračun vseh možnih poti oziroma časovnih linij. Program postopoma prenaša vrednosti iz trenutne vrstice v naslednjo, pri čemer se ob navadnih znakih vrednost prenese neposredno navzdol, ob razcepu pa se trenutno število linij podvoji in razporedi levo ter desno. Ta pristop omogoča učinkovito seštevanje vseh kombinacij brez potrebe po eksplicitnem preiskovanju vsake posamezne poti. Na koncu algoritem sešteje vse vrednosti v zadnji vrstici, kar poda končno število vseh aktivnih časovnih linij.
