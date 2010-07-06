all:
	cd latexTest && $(MAKE)
	cd ideallibrary && $(MAKE)
	cd kdeespana && $(MAKE)
	cd kdeespana-asolif && $(MAKE)
	cd quijote2010 && $(MAKE)

clean:
	cd latexTest && $(MAKE) clean
	cd ideallibrary && $(MAKE) clean
	cd kdeespana && $(MAKE) clean
	cd kdeespana-asolif && $(MAKE) clean
	cd quijote2010 && $(MAKE) clean
