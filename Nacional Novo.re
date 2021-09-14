numero saida = 0
numero velocidade = 110
booleano temp = verdadeiro
numero tempCont = 0
numero ULTIMO = 0
numero triangulo = 0
numero recuar = 0
numero graus = 0
numero vitimapos = 0
numero antigapos = 0
numero ULTRA2 = 0
booleano V2 = falso
booleano aindanaoachou = verdadeiro
numero resgatepos = 0
numero tipo = 0
numero re = 0
numero ri = 0
numero VitimasCont = 0
numero luz5 = 0
booleano azul = falso
numero veze = 0
numero alto = 0
numero bussola = 0
numero baixo = 0
booleano liberado = verdadeiro
booleano achouresgate = falso

tarefa alinhar {
    #escrevernumero(2, direcao())
	se(direcao()>230 e direcao()<300)entao{
	    #escrever(1, "270")
	    rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=270)farei{esquerda(500)}
		parar()
	} senao se(direcao()>300 ou direcao()<40)entao{
		#escrever(1, "0")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=0)farei{esquerda(500)}
		parar()
	} senao se(direcao()>40 e direcao()<130)entao{
		#escrever(1, "90")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=90)farei{esquerda(500)}
		parar()
	} senao se(direcao()>130 e direcao()<230)entao{
		#escrever(1, "180")
		rotacionar(1000, 5)
		enquanto(arredondar(direcao())!=180)farei{esquerda(500)}
		parar()
	}
}

tarefa seguelinha{
    se(luz(1)<50)entao{
        se(luz(2)<50) entao{
            escrever(1, "DOIS PRETOS")
            escrevernumero(2, ULTIMO)
            frente(150)
            esperar(300)
            se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{frente(150) esperar(300)}
            se(ULTIMO == 2)entao{
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1800)farei{direita(1000)}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{esquerda(1000)}
                    parar()
                }
            } senao se(ULTIMO == 1)entao{
                zerartemporizador()
                enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1800)farei{esquerda(1000)}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
                    parar()
                }
            }
            zerartemporizador()
        } senao{
            ULTIMO = 2
            direita(1000)
            zerartemporizador()
        }
    } senao{
        se(luz(2)<50)entao{
            ULTIMO = 1
            esquerda(1000)
            zerartemporizador()
        } senao {
            frente(150)
        }
    }
}

tarefa verde{
	se(cor(1)=="VERDE")entao{
		parar()
        escrever(1, "VERDE PARA A DIREITA")
        enquanto(cor(1)=="VERDE")farei{
            se(cor(2)=="VERDE")entao{V2 = verdadeiro}
            frente(150)
        }
        parar()
        se(V2 == falso)entao{
            frente(150)
            esperar(300)
            direita(1000)
            esperar(600)
            enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
            parar()
        } senao {
            frente(150)
            esperar(300)
            rotacionar(1000, 90)
            enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
            parar()
        }
        V2 = falso
	} senao se(cor(2)=="VERDE")entao{
        parar()
		escrever(1, "VERDE PARA A ESQUERDA")
        enquanto(cor(2)=="VERDE")farei{
            se(cor(1)=="VERDE")entao{V2 = verdadeiro}
            frente(150)
        }
        parar()
        se(V2 == falso)entao{
            frente(150)
            esperar(300)
            esquerda(1000)
            esperar(600)
            enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{esquerda(1000)}
            parar()
        } senao {
            frente(150)
            esperar(300)
            rotacionar(1000, 90)
            enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{direita(1000)}
            parar()
        }
        V2 = falso
	} senao {
		seguelinha()
	}
}

tarefa obstaculo{
    se (ultra(1) < 25) entao{
		zerartemporizador()
		se(cor(5)=="BRANCO" e luz(5)>45) entao {
			frente(100)
			esperar(100)
			parar()
			zerartemporizador()
		} senao{
			enquanto(ultra(1)<50)farei{esquerda(1000)}
			parar()
			rotacionar(1000, negativo(20))

            zerartemporizador()
            enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<400)farei{frente(300)}
            parar()
            se(cor(1)=="PRETO" ou cor(2)=="PRETO")entao{
                escrever(1, "OBSTACULO PARA ESQUERDA")
                frente(300)
                esperar(300)
                rotacionar(1000, negativo(45))
                zerartemporizador()
                enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                parar()
            } senao {
                zerartemporizador()
                enquanto(cor(2)=="BRANCO" e (ultra(2)<50) e ultra(1)>20 e ultra(2)>25)farei{frente(100)}
                parar()
                rotacionar(1000, 45)
                frente(300)
                esperar(400)
                enquanto(ultra(2)<50)farei{frente(300)}
                parar()
                rotacionar(1000, 55)
                zerartemporizador()
                enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<300)farei{frente(300)}
                parar()
                se(cor(1)=="PRETO" ou cor(2)=="PRETO")entao{
                    escrever(1, "OBSTACULO NORMAL")
                    frente(300)
                    esperar(300)
                    rotacionar(1000, negativo(55))
                    zerartemporizador()
                    enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                    parar()
                } senao {
                    zerartemporizador()
                    enquanto(cor(2)=="BRANCO" e (ultra(2)<50) e ultra(1)>20 e ultra(2)>25)farei{frente(100)}
                    parar()
                    rotacionar(1000, 45)
                    frente(300)
                    esperar(300)
                    enquanto(ultra(2)<50)farei{frente(300)}
                    parar()
                    rotacionar(1000, 55)
                    zerartemporizador()
                    enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<300)farei{frente(100)}
                    parar()
                    escrever(1, "OBSTACULO PARA DIREITA")
                    frente(300)
                    esperar(400)
                    rotacionar(1000, negativo(60))
                    zerartemporizador()
                    enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
                    parar()
                }
            }
	    }
	zerartemporizador()
	} senao{
		verde()
 	}
}
tarefa rampa{
    se(arredondar(inclinacao())==340 e ultra(2)>100)entao{
        escrever(1, "ELEVAÇÂO DETECTADA")
        zerartemporizador()
        enquanto(arredondar(inclinacao())<345)farei{obstaculo()}
        parar()
        antigapos = arredondar(inclinacao())
        esperar(2000)
        escrever(1, "RAMPA FINALIZADA")
        se(antigapos == arredondar(inclinacao()))entao{
            escrever(2, "RAMPA")
            escrever(3, "CONTINUANDO RAMPA")
            zerartemporizador()
            enquanto(temporizador()<2500)farei{obstaculo()}
            parar()
            frente(300)
            esperar(100)
        }
        zerartemporizador()
        #limparconsole()
    } senao {
        obstaculo()
    }
}
tarefa seperdeu{
    se(temporizador()>1000 e temp==verdadeiro)entao{
		parar()
		zerartemporizador()
		enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1300)farei{
			se(ULTIMO==1)entao{
				direita(1000)
			} senao se (ULTIMO==2)entao{
				esquerda(1000)
			} senao {
				direita(1000)
			}
		}
		parar()
		se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
			zerartemporizador()
			enquanto(cor(2)=="BRANCO" e temporizador()<2600)farei{
				se(ULTIMO==1)entao{
					esquerda(1000)
				} senao se (ULTIMO==2)entao{
					direita(1000)
				} senao {
					esquerda(1000)
				}
			}
			zerartemporizador()
			se(cor(2)=="BRANCO")entao{
				se(ULTIMO==1)entao{
					direita(1000)
					esperar(1300)
				} senao se (ULTIMO==2)entao{
					esquerda(1000)
					esperar(1300)
				} senao {
					direita(1000)
					esperar(1300)
				}
				se(tempCont == 0)entao{
                    zerartemporizador()
					tempCont = tempCont + 1
					parar()
				}
			}
			zerartemporizador()
		}
	}senao {
		rampa()
	}
}
tarefa vermelhoF {
    se(cor(1)=="VERMELHO" ou cor(2)=="VERMELHO")entao{
        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO")farei{tras(200)}
        parar()
    } senao {
        seperdeu()
    }
}
tarefa trianguloProc {
    enquanto(luz(3)>8)farei{
        se(ultra(1)<40)entao{
            rotacionar(1000, 90)
            alinhar()
        }
        frente(300)
    }
    parar()
    girarbaixo(1000)
    abrir(1)
    baixar(600)
    enquanto(temvitima())farei{esperar(1)}
    esperar(500)
    fechar(1)
    levantar(600)
    girarcima(1000)
}
tarefa pegar {
	abrir(1)
	baixar(1000)
	parar()
	enquanto(temvitima()==falso e ultra(1)>35)farei{frente(200)}
    frente(300)
	levantar(500)
	parar()
	levantar(500)
	fechar(1)
	tras(300)
    esperar(recuar + 1000)
	parar()
	frente(300)
	esperar(150)
	rotacionar(1000, negativo(90))
	alinhar()
}
tarefa resgate{
    alinhar()
    #cuboazul()
    enquanto(luz(3)>8)farei{
        se(ultra(1)<30)entao{
            rotacionar(1000, 90)
            alinhar()
        } senao {
            frente(300)
        }
    }
    se(azul == verdadeiro)entao{
        baixar(500)
        parar()
        baixar(500)
        levantar(1000)
    }
    alinhar()
    enquanto(verdadeiro)farei{
        alinhar()
        ULTRA2 = ultra(2) - 3
        se(resgatepos==0)entao{
            zerartemporizador()
            enquanto(ultra(2)>ULTRA2 e toque(1)==falso e ultra(1)<254)farei{
                escrevernumero(1, ULTRA2)
                se(ultra(2)>ULTRA2)entao{
                    ULTRA2 = ultra(2) - 1
                }
                tras(300) 
            }
        } senao {
            enquanto(ultra(2)>ULTRA2 e toque(1)==falso)farei{
                escrevernumero(1, ULTRA2)
                se(ultra(2)>ULTRA2)entao{
                    ULTRA2 = ultra(2) - 1
                }
                tras(300) 
            }
        }
        se(toque(1)==verdadeiro ou ultra(1)>254)entao{
            resgatepos = 1
            rotacionar(1000, negativo(90))
            tras(300)
            esperar(1000)
            acenderled("VERMELHO")
            parar()
        } senao {
            re = ultra(2)
            tras(300)
            esperar(100)
            parar()
            levantar(1000)
            rotacionar(1000,90)
            alinhar()
            se(ultra(1)>500)entao{
                escrever(1, "PAREDE NÂO ENCONTRADA")
                abrir(1)
                baixar(1000)
                enquanto(temvitima()==falso)farei{frente(300)}
                parar()
                tras(300)
                esperar(100)
                parar()
                levantar(1000)
            } senao {
                escrever(1, "POSIÇÃO DA VITIMA EM RELAÇÂO A PAREDE ENCONTRADA")
                ri = multiplicar((re - ultra(1) - 55), negativo(1))
                escrevernumero(2, ri)
                esperar(1000)
                zerartemporizador()
                enquanto(ultra(1)>ri)farei{frente(300)}
                parar()
                recuar = temporizador()
                frente(300)
                esperar(250)
                parar()
            }
            se(VitimasCont < 2)entao{
                parar()
                esperar(500)
                se(cor(3)=="BRANCO")entao{
                    escrever(1, "VITIMA BRANCA")
                    VitimasCont = VitimasCont + 1
                    escrevernumero(2, VitimasCont)
                    tras(300)
                    esperar(300)
                    parar()
                    pegar()
                    resgatepos = 0
                    trianguloProc()
                } senao se(cor(3)=="PRETO")entao{
                    escrever(1, "VITIMA PRETO VOLTANDO")
                    escrevernumero(2, VitimasCont)
                    enquanto(toque(1)==falso)farei{tras(300)}
                    parar()
                    frente(300)
                    esperar(150)
                    rotacionar(1000, negativo(90))
                    alinhar()
                    tras(300)
                    esperar(100)
                }
            } senao {
                escrever(1, "VITIMA PRETA, PERMITIDO RESGATAR")
                tras(300)
                esperar(300)
                parar()
                resgatepos = 0
                pegar()
                trianguloProc()
            }
        }
    }
}
tarefa resgateIdent {
    se(ultra(2) <= 50 e liberado == verdadeiro e achouresgate == falso) entao{
        parar()
        bussola = truncar(direcao())
        enquanto(veze < 10) farei{
            esquerda(1000)
            esperar(100)
            se(ultra(1) > 1000) entao{
                alto =  alto + 1
            } senao se(ultra(2) > 50) entao{
                baixo = baixo + 1
            }
            se(alto >= 5) entao{
                parar()
                interromper()
            }
            veze = veze + 1
        }
        veze = 0
        se(alto > baixo) entao{
            escrever(1, "Não é o resgate")
            liberado = falso
            frente(300)
            esperar(100)
        } senao se(alto == baixo) entao{
            escrever(1, "Não é o resgate")
            liberado = falso
            frente(300)
            esperar(100)
        }senao{
                escrever(1, "É o resgate")
                achouresgate = verdadeiro
                enquanto(truncar(direcao()) != bussola) farei{
                    se(truncar(direcao()) < bussola) entao{
                        direita(1000)
                    } senao {
                        parar()
                        interromper()
                    }
                }
                resgate()
        }
        enquanto(truncar(direcao()) != bussola) farei{
            se(truncar(direcao()) < bussola) entao{
                direita(1000)
            } senao {
                parar()
                interromper()
            }
        }
        parar()
        alto = 0
        veze = 0
        baixo = 0
    } senao se(ultra(2) > 1000 e liberado == falso e achouresgate == falso) entao{
        liberado = verdadeiro
    } senao { #Inútil
        vermelhoF() #Inútil
    } #Inútil
}
inicio
velocidadeatuador(150)
levantar(900)
zerartemporizador()
enquanto(verdadeiro)farei{
    se((cor(3)=="CIANO" ou cor(3)=="AZUL") e luz(3)<40 e ultra(1)>40)entao{
        parar()
        tras(300)
        esperar(300)
        parar()
        abrir(1)
        baixar(1000)
        frente(300)
        esperar(400)
        parar()
        frente(300)
        levantar(600)
        parar()
        fechar(1)
        tras(300)
        esperar(1000)
        azul = verdadeiro
    } senao {
        resgateIdent()
    }
}
fim