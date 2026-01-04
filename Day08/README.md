# Day08

V prvem delu naloge program prebere 3D koordinate točk in izračuna kvadrat razdalje med vsemi možnimi pari, ki jih nato uredi od najbližjega do najbolj oddaljenega. Program poveže točke, ki jih določa prvih tisoč najkrajših povezav v urejenem seznamu. Po opravljenem združevanju prepozna vse nastale komponente in izmeri njihove velikosti. Rešitev predstavlja produkt velikosti treh največjih skupin točk, ki so se v tem postopku izoblikovale.

Drugi del se osredotoča na iskanje minimalnega vpetega drevesa s Kruskalovim algoritmom, kjer postopoma dodajamo najkrajše razpoložljive povezave. Postopek se izvaja, dokler število ločenih komponent ne pade na ena, kar pomeni, da so vse točke med seboj povezane v enotno mrežo. Program ob tem dogodku zabeleži zadnjo dodano povezavo in njeni krajišči. Končni rezultat izračuna kot produkt koordinat X dveh točk, ki sta s to zadnjo povezavo dokončno združi.
