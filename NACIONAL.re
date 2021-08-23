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
numero ppos = 0
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

			frente(300)
			esperar(400)
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
            enquanto(cor(2)=="BRANCO" e temporizador()<300)farei{frente(100)}
            parar()
            frente(300)
            esperar(300)
            rotacionar(1000, negativo(55))
            zerartemporizador()
            enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
            parar()
		
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
tarefa procurartriangulo {
    se (ultra(1) >= 350) entao{
		escrever(1, "Tipo 2")
		enquanto(aindanaoachou) farei{
			se(luz(3) <= 10) entao{
				escrever(2, "Posição 1")
                triangulo = 1
				aindanaoachou = falso
			}senao se(arredondar(ultra(2)) > 175 e arredondar(ultra(2)) < 190) entao{
				escrevernumero(3, ultra(2))
				se (ultra(2) > 175) entao{
					tras(200)
					esperar(350)
					se(ultra(2) > 500) entao{
							frente(200)
						esperar(350)
						escrever(3, "Falso positivo")
					} senao {
							frente(200)
						esperar(350)
						se (ultra(1) < 100) entao{
								escrever(2, "Posição 2")
                                triangulo = 2
						} senao {
								escrever(2, "Posição 3")
                                triangulo = 3
						}
						aindanaoachou = falso
						#rotacionar(1000, 90)
					}
				}
			}senao {
				frente(400)
			}
		}
	} senao {		
		escrever(1, "Tipo 1")
		enquanto(aindanaoachou) farei{
			se(luz(3) <= 10) entao{
				escrever(2, "Posição 1")
                triangulo = 1
				aindanaoachou = falso
			}senao se(arredondar(ultra(2)) > 290 e arredondar(ultra(2)) < 305) entao{
				se (ultra(2) > 290) entao{
					tras(200)
					esperar(350)
					se(ultra(2) > 500) entao{
							frente(200)
						esperar(350)
						escrever(3, "Falso positivo")
					} senao {
							frente(200)
						esperar(350)
						se (ultra(1) < 100) entao{
								escrever(2, "Posição 2")
                                triangulo = 2
						} senao {
								escrever(2, "Posição 3")
                                triangulo = 3
						}
						aindanaoachou = falso
						#rotacionar(1000, 90)
					}
				}
			}senao {
				frente(300)
			}
		}
	}
}
tarefa procurarV {
    ULTRA2 = ultra(2) - 3
    zerartemporizador()
    enquanto(ultra(2)>ULTRA2 e ultra(1)>30)farei{
        escrevernumero(1, ULTRA2)
        se(ultra(2)>ULTRA2)entao{
            ULTRA2 = ultra(2) - 1
        }
        frente(300)
    }
    parar()
    ULTRA2 = ultra(2)
    enquanto(ultra(2)<ULTRA2)farei{frente(300)}
    parar()
    escrever(1, "VITIMA ENCONTRADA")
    frente(300)
    esperar(20)
    parar()
    fechar(1)
    levantar(900)
}
tarefa depositar{
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
tarefa resgatarvitima{
    se(ultra(2)<ULTRA2)entao{
        #escrevernumero(1, ultra(2))
        vitimapos = ultra(2)
        escrevernumero(3, vitimapos)
        
        se(ultra(2)<vitimapos)entao{
            vitimapos = ultra(2)
        }
        rotacionar(1000, 90)
        alinhar()
        se(vitimapos<40)entao{
            frente(100)
            esperar(1200)
            tras(300)
            esperar(300)
        }
        escrever(1, "INDO ATRÁS DA VITIMA")
        abrir(1)
        baixar(600)
        zerartemporizador()
        enquanto(temvitima()==falso e ultra(1)>45 e temporizador()<5000)farei{frente(200)}
        parar()
        se(ultra(1)<45)entao{
            escrever(1, "PAREDE")
            fechar(1)
            levantar(600)
        } senao se(temvitima())entao{
            escrever(1, "FAZENDO RESGATE DA VITIMA")
            frente(300)
            levantar(300)
            parar()
            fechar(1)
            levantar(300)
            parar()
            esperar(500)
            # Resgatar a vitima
        } senao {
            fechar(1)
            levantar(600)
            enquanto(toque(1)==falso)farei{tras(300)}
            parar()
        }
    }
}
tarefa resgate{
    se((arredondar(luz(1))==85 ou arredondar(luz(1))==59) e (arredondar(luz(2))==59 ou arredondar(luz(2))==85))entao{
        parar()
        acenderled("VERDE")
        escrever(1, "RESGATE CONFIRMADO")
        frente(300)
        esperar(750)
        alinhar()
        temp = falso
        rotacionar(1000, negativo(40))
        frente(300)
        esperar(500)
        rotacionar(1000, 40)
        tras(300)
        esperar(500)
        parar()
        abrir(1)
        baixar(1000)
        se(ultra(2)>500)entao{saida = 3}
        se(ultra(1)>500)entao{saida = 1}
        escrever(1, "COMEÇAR A PROCURAR TRIANGULO")

        procurartriangulo()

        escrever(1, "TRIANGULO ENCONTRADO")
        se(temvitima()==verdadeiro)entao{
            parar()
            abrir(1)
            girarbaixo(1000)
            baixar(600)
            enquanto(temvitima())farei{esperar(1)}
            esperar(500)
            fechar(1)
            levantar(600)
            girarcima(1000)
        }
        enquanto(verdadeiro)farei{
            ppos = ppos + 1
            se(ppos>2)entao{
                ppos = 2
            }
            escrevernumero(4, ppos)
            procurarV()
            resgatarvitima()
            se(triangulo==3)entao{
                se(temvitima()==verdadeiro)entao{
                    se(ppos == 1) entao{
                        se(ultra(1)>140)entao{
                            enquanto(ultra(1)>140)farei{frente(300)}
                            parar()
                        }senao{
                            enquanto(ultra(1)<140)farei{tras(300)}
                            parar()
                        }
                        rotacionar(1000, 45)
                    } senao se(ppos==2)entao{
                        se(ultra(1)>140)entao{
                            enquanto(ultra(1)>180)farei{frente(300)}
                            parar()
                        }senao{
                            enquanto(ultra(1)<180)farei{tras(300)}
                            parar()
                        }
                        rotacionar(1000, 135)
                    }
                    enquanto(luz(3)>8 e ultra(1)>70)farei{frente(300)}
                    parar()
                    se(ultra(1)<70)entao{
                        se(ultra(2)<100)entao{
                            rotacionar(1000, negativo(45))
                            enquanto(luz(3)>8)farei{frente(300)}
                            parar()
                            rotacionar(1000, 45)
                        } senao {
                            rotacionar(1000, 45)
                            enquanto(luz(3)>8)farei{frente(300)}
                            parar()   
                            rotacionar(1000, negativo(45))
                        }
                    }
                    depositar()
                    rotacionar(1000, 90)
                    enquanto(ultra(1)>30)farei{frente(300)}
                    parar()
                    rotacionar(1000, 45)
                    alinhar()
                } senao {
                    ppos = 0
                    rotacionar(1000, 90)
                    alinhar()
                }
            }
        }
    } senao {
        rampa()
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
                    enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1500)farei{tras(150)}
                    parar()
					tras(150)
                    esperar(300)
					tempCont = tempCont + 1
					parar()
				}
			}
			zerartemporizador()
		}
	}senao {
		resgate()
	}
}
inicio
velocidadeatuador(150)
levantar(900)
zerartemporizador()
enquanto(verdadeiro)farei{
    se(cor(1)=="VERMELHO" ou cor(2)=="VERMELHO")entao{
        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO")farei{tras(200)}
        parar()
    } senao {
        seperdeu()
    }
}
fim