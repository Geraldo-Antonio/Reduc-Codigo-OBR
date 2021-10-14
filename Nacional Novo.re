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
booleano podesair = falso
booleano azul = falso
numero bussola = 0
numero baixo = 0
booleano achouresgate = falso
numero T = 241
numero vezesfrente = 0
booleano liberadosaida = verdadeiro
booleano achousaida = falso
numero tentativa = 0
booleano douglasF = falso
numero ultraVerdadeiro = 0
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

tarefa dash{
	tras(300)
	esperar(330)
	parar()
	frente(300)
	esperar(330)
	parar()
	enquanto(inclinacao() > 340) farei{
		tras(100)
		esperar(50)
		parar()
		levantar(500)
		esperar(150)
	}
}

tarefa seguelinha{
    se(luz(1)<50)entao{
        se(luz(2)<50) entao{
            escrever(1, "DOIS PRETOS")
            escrevernumero(2, ULTIMO)
            frente(150)
            esperar(250)
            se(cor(1)=="VERDE" ou cor(2)=="VERDE")entao{frente(150) esperar(300)}
            se(ULTIMO == 2)entao{
                zerartemporizador()
                enquanto(temporizador()<1800)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						direita(1000)
					} senao{
						interromper()
					}
				}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    tras(300)
                    esperar(150)
                    zerartemporizador()
                    enquanto(temporizador()<3600)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						esquerda(1000)
					} senao{
						interromper()
					}
				}
                    parar()
                    se(temporizador()>3600)entao{
                        direita(1000)
                        esperar(3350)
                    }
                }
            } senao se(ULTIMO == 1)entao{
                zerartemporizador()
                enquanto(temporizador()<1800)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						esquerda(1000)
					} senao{
						interromper()
					}
				}
                parar()
                se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
                    tras(300)
                    esperar(150)
                    zerartemporizador()
                    enquanto(temporizador()<3600)farei{
					se(cor(1) != "PRETO" e cor(2) != "PRETO") entao{
						direita(1000)
					} senao{
						interromper()
					}
					}
                    parar()
                    se(temporizador()>3600)entao{
                        esquerda(1000)
                        esperar(3350)
                    }
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

tarefa antivitima{
    velocidadeatuador(100)
	baixar(300)
	esperar(300)
	tras(200)
	esperar(100)
	parar()
	levantar(300)
	esperar(200)
    velocidadeatuador(150)
}

tarefa verde{
	se(cor(1) == "VERDE" ou cor(2) == "VERDE") entao {
		parar()
		frente(100)
		esperar(30)
		zerartemporizador()
		enquanto(temporizador() < 100) farei{
			se(cor(1) == "VERDE" e cor(2) == "VERDE") entao{
				interromper()
			} senao{
				esquerda(1000)
			}			
		}
		zerartemporizador()
		enquanto(temporizador() < 100) farei{
			se(cor(1) == "VERDE" e cor(2) == "VERDE") entao{
				zerartemporizador()
				interromper()
			} senao{
				direita(1000)
			}			
		}
		zerartemporizador()
	}
	se(cor(1) == "VERDE" e cor(2) == "VERDE") entao {
		parar()
		rotacionar(1000,180)
	}senao se(cor(1)=="VERDE" e cor(2) != "VERDE")entao{
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
            enquanto(cor(2)=="BRANCO" e cor(1)=="BRANCO" e temporizador()<500)farei{frente(300)}
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
                    esperar(350)
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
                    esperar(300)
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
    se(temporizador()>800 e temp==verdadeiro)entao{
		parar()
		zerartemporizador()
		enquanto(cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1600)farei{
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
			enquanto(cor(2)=="BRANCO" e temporizador()<3200)farei{
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
					esperar(1600)
				} senao se (ULTIMO==2)entao{
					esquerda(1000)
					esperar(1600)
				} senao {
					direita(1000)
					esperar(1600)
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
        zerartemporizador()
        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO" e temporizador()<700)farei{tras(200)}
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
    se(temvitima()==falso)entao{
        VitimasCont = VitimasCont - 1
    } senao {
        se(temperatura()>35 ou VitimasCont>1)entao{
            escrever(1, "VITIMA CONFIRMADA EXECUTANDO RESGATE")
            parar()
            girarbaixo(500)
            abrir(1)
            baixar(600)
            enquanto(temvitima())farei{dash()}
            esperar(500)
            fechar(1)
            levantar(600)
            girarcima(500)
        } senao {
            escrever(1, "VITIMAS VIVAS DEVEM SER PRIORIZADAS")
            VitimasCont = VitimasCont - 1
            tras(300)
            esperar(1000)
            rotacionar(1000, 90)
            abrir(1)
            baixar(1000)
            frente(300)
            esperar(200)
            tras(300)
            esperar(200)
            fechar(1)
            rotacionar(1000, negativo(90))
            frente(300)
            esperar(600)
        }
    }
    alinhar()
}
tarefa pegar {
	abrir(1)
	baixar(1000)
	parar()
	enquanto(temvitima()==falso e ultra(1)>44)farei{
        se(inclinacao() > 5) entao{
            #tras(200)
            frente(300)
        }senao {
            frente(200)
        }
	}
    frente(300)
	se(ultra(1) <= 44) entao{
		fechar(1)
		levantar(500)
		parar()
		levantar(500)
	} senao{
		levantar(500)
		parar()
		levantar(500)
		fechar(1)
	}
	antivitima()
	enquanto(toque(1)==falso e cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{tras(300)}
	parar()
    se(cor(1)!="BRANCO" ou cor(2)!="BRANCO")entao{
        frente(300)
        esperar(700)
    }
	frente(300)
	esperar(150)
	rotacionar(1000, negativo(90))
	alinhar()
}
tarefa resgate{
    alinhar()
    #cuboazul()
    enquanto(ultra(1)>500)farei{
        rotacionar(1000, 90)
    }
    triangulo = triangulo + 1
    escrevernumero(1, triangulo)
    enquanto(luz(3)>8)farei{
        se(ultra(1)<30 ou cor(1) == "VERDE")entao{
            triangulo = triangulo + 1
            escrever(1, "O VALOR DO TRIANGULO É:")
            escrevernumero(2, triangulo)
			se(ultra(2) > 60) entao{
            	rotacionar(1000, 90)
			} senao{
            	rotacionar(1000, negativo(90))
			}
            alinhar()
        } senao {
            frente(300)
        }
    }
    #Ajuste
    tras(300)
    esperar(200)
    se(temKit())entao{
        se(ultra(2)<30)entao{
            rotacionar(1000, negativo(45))
            frente(300)
            esperar(500)
            rotacionar(1000, 90)
            #############################
            girarbaixo(1000)
            parar()
            abrir(1)
            baixar(600)
            esperar(1000)
            se(temKit() == verdadeiro) entao{
                dash()
            }
            fechar(1)
            levantar(600)
            parar()
            girarcima(1000)
            ##############################
            rotacionar(1000, 90)
            tras(300)
            esperar(500)
            rotacionar(1000, negativo(45))
        } senao{
            rotacionar(1000, 45)
            frente(300)
            esperar(500)
            rotacionar(1000, negativo(90))
            #############################
            girarbaixo(1000)
            parar()
            abrir(1)
            baixar(600)
            esperar(1000)
            se(temKit() == verdadeiro) entao{
                dash()
            }
            fechar(1)
            levantar(600)
            parar()
            girarcima(1000)
            ##############################
            rotacionar(1000, 90)
            tras(300)
            esperar(500)
            rotacionar(1000, negativo(45))
        }
    }
    alinhar()
    se(tipo==1)entao{
        se(triangulo==1)entao{
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
            T = 350
        } senao se(triangulo==2)entao{
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
            T = 241
        } senao se(triangulo==3)entao{
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
            T = 350
        }
    } senao se(tipo==2)entao{
        se(triangulo==1)entao{
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
            T = 241
        } senao se(triangulo==2)entao{
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
            T = 350
        } senao se(triangulo==3)entao{
            T = 241
            escrever(1, "Tipo de arena e valor do T")
            escrevernumero(2, tipo)
            escrevernumero(3, T)
        }
    }
    enquanto(VitimasCont < 3 e resgatepos < 2)farei{
        escrevernumero(3, T)
        #alinhar()
        ULTRA2 = ultra(2) - 1
        escrevernumero(1, ULTRA2)
        enquanto(ultra(2) > ULTRA2 e toque(1)==falso e ultra(1)<T)farei{
            se(ultra(2)>500)entao{
                ULTRA2 = 450
            } senao {
                ULTRA2 = ultra(2) - 1
            }
            escrevernumero(1, ULTRA2)
            escrevernumero(2, ultra(2))
            tras(300)
        }
        parar()
        se(toque(1)==verdadeiro ou ultra(1)>T)entao{
            se(T == 350)entao{
                T = 241
            } senao {
                T = 350
            }
            resgatepos = resgatepos + 1
            rotacionar(1000, negativo(90))
            alinhar()
            ULTRA2 = ultra(2) - 1
            #tras(300)
            #esperar(1000)
            acenderled("VERMELHO")
            esperar(1000)
            parar()
        } senao {
            escrever(3, "POSSIVEL VITIMA")
            re = ultra(2)
            tras(300)
            esperar(100)
            parar()
            levantar(1000)
            rotacionar(1000,90)
            alinhar()
            se(ultra(1)>500)entao{
                escrever(1, "PAREDE NÂO ENCONTRADA")
                rotacionar(1000, negativo(90))
                tras(300)
                esperar(100)
                rotacionar(1000, 90)
                abrir(1)
                baixar(1000)
                parar()
                enquanto(temvitima()==falso e ultra(1)>35 e cor(1)=="BRANCO" e cor(2)=="BRANCO")farei{frente(200)}
                parar()
                se(cor(1)!="BRANCO" ou cor(2)!="BRANCO")entao{
                    tras(300)
                    esperar(800)
                    parar()
                    levantar(500)
                    parar()
                    levantar(500)
                    fechar(1)
                    parar()
                } senao {
                    douglasF = verdadeiro
                    frente(300)
                    levantar(500)
                    parar()
                    levantar(500)
                    fechar(1)
                    parar()
                    esperar(500)
                    parar()
                    farei {
                        rotacionar(1000, 90)
                    } enquanto(ultra(1)>500)
                }
            } senao {
                escrever(1, "POSIÇÃO DA VITIMA EM RELAÇÂO A PAREDE ENCONTRADA")
                ri = multiplicar((re - ultra(1) - 42), negativo(1))
                escrevernumero(2, ri)
                esperar(1000)
                zerartemporizador()
                enquanto(ultra(1)>ri)farei{frente(200)}
                parar()
                recuar = temporizador()
                frente(100)
                esperar(250)
                parar()
            }
            se(VitimasCont < 2)entao{
                parar()
                esperar(500)
                se(douglasF == verdadeiro)entao{
                    VitimasCont = VitimasCont + 1
                    resgatepos = 0
                    trianguloProc()
                    douglasF = falso
                }senao se(cor(3)=="BRANCO" e temperatura()>35)entao{
                    escrever(1, "VITIMA BRANCA")
                    VitimasCont = VitimasCont + 1
                    escrevernumero(2, VitimasCont)
                    tras(300)
                    esperar(300)
                    parar()
                    pegar()
                    resgatepos = 0
                    trianguloProc()
                } senao {
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
                VitimasCont = 3
                tras(300)
                esperar(300)
                parar()
                resgatepos = 0
                pegar()
                trianguloProc()
                se(T == 350)entao{
                    T = 241
                } senao {
                    T = 350
                }
            }
        }
    }
    escrever(1, "TODAS AS VITIMAS RESGATADAS")
    tras(300)
    esperar(600)
    parar()
    rotacionar(1000, 90)
    alinhar()
    frente(300)
    esperar(1000)
    parar()
    enquanto(achousaida == falso) farei {
		direita(1000)
        se(ultra(1)<50)entao{
            tras(300)
            esperar(1000)
        }
		se(ultra(1) > 450 e liberadosaida == verdadeiro) entao{
			direita(600)
			esperar(400)
			enquanto(verdadeiro) farei{
				frente(200)
				vezesfrente = vezesfrente + 1
				se(ultra(2) < 10 ou ultra(1) < 35 ou cor(1) == "VERMELHO" ou cor(2) == "VERMELHO" ou (truncar(corazul(1)) - truncar(corverde(1))) >= 6  e truncar(corvermelha(1)) < truncar(corverde(1)) ou (truncar(corazul(1)) - truncar(corverde(1))) >= 6 e truncar(corvermelha(2)) < truncar(corverde(2))) entao{
					liberadosaida = falso
					interromper()
				}
				se(truncar(corvermelha(1)) == 24 e truncar(corverde(1)) == 67 e truncar(corazul(2)) == 37 ou cor(1) == "CIANO" ou cor(2) == "CIANO" ou cor(1) == "VERDE" e cor(2) == "VERDE") entao{
					escrever(1, "Achamos")
					achousaida = verdadeiro
                    enquanto(cor(1) == "BRANCO" ou cor(2) == "BRANCO") farei{
						frente(100)
					}
					enquanto(cor(1) == "VERDE" ou cor(2) == "VERDE") farei{
						frente(100)
					}
					parar()
					frente(300)
                    esperar(200)
                    zerartemporizador()
                    enquanto(cor(1)!="PRETO" e cor(2)!="PRETO" e temporizador()<2000)farei{esquerda(1000)}
                    parar()
                    se(cor(1)!="PRETO" e cor(2)!="PRETO")entao{
                        zerartemporizador()
                        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO" e temporizador()<4000)farei{direita(1000)}
                        parar()
                    }
                    se(cor(1)!="PRETO" e cor(2)!="PRETO")entao{
                        esquerda(1000)
                        esperar(2000)
                        frente(300)
                        esperar(300)
                        zerartemporizador()
                        enquanto(cor(1)!="PRETO" e cor(2)!="PRETO")farei{esquerda(1000)}
                        parar()
                    }
                    enquanto(cor(1)!="VERMELHO" ou cor(2)!="VERMELHO")farei{
                        seperdeu()
                    }
                    frente(300)
                    esperar(300)
                    parar()
                    esperar(10000)
                    interromper()
				}
			}
			se(achousaida == falso) entao{
				liberadosaida = falso
				enquanto(vezesfrente >= 0) farei{
					tras(300)
					escrevernumero(1, vezesfrente)
					vezesfrente = vezesfrente - 4
				}
				tentativa = tentativa + 1
			}
		} senao se(ultra(1) < 450 e liberadosaida == falso) entao{
			se(truncar(ultra(1)) < 450) entao{
				liberadosaida = verdadeiro
			}
		}
	}
}


tarefa resgateIdent {
    se(achouresgate == falso e (truncar(corazul(1)) - truncar(corverde(1))) >= 6  e truncar(corvermelha(1)) < truncar(corverde(1)) ou (truncar(corazul(1)) - truncar(corverde(1))) >= 6 e truncar(corvermelha(2)) < truncar(corverde(2))) entao{
        escrever(3, "É o resgate")
		frente(300)
		esperar(600)
		parar()
        achouresgate = verdadeiro
		se(truncar(ultra(1)) >= 350 e truncar(ultra(1)) < 1000 ou truncar(ultra(2)) <= 230) entao{
			escrever(2, "Tipo 1")
            tipo = 1
		} senao {
			escrever(2, "Tipo 2")
            tipo = 2
		}
		tras(300)
		esperar(500)
		parar()
        resgate()
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