enquanto(verdadeiro)farei{
			triangulo = triangulo + 1
            se(ultra(3)>900 e triangulo==1)entao{
                saida = 3
            }senao se(triangulo == 1 e ultra(1)>1000)entao{
                saida = 1
            } senao se(triangulo==2 e ultra(1)>1000){
                saida = 2
            } senao se(triangulo == 2)entao{
                tras(300)
                esperar(300)
                se(toque(1!=falso))entao{
                    saida = 1
                }
            } senao se (triangulo==3 e ultra(3)>900) entao{
                saida = 2
            } senao se (triangulo==3 e ultra(1)>900) entao{
                saida = 3
            }
			frente(300)
			esperar(300)
			tras(300)
			esperar(300)
			parar()
			se(toque(1)==falso)entao{
				se(triangulo==1)entao{saida=1}
				senao se(triangulo==2)entao{saida=2}
			}
			velocidadeatuador(150)
			abrir(1)
			baixar(600)
			enquanto(ultra(1)>120)farei{frente(300)}
			parar()
			levantar(600)
			fechar(1)
			velocidadeatuador(50)
			enquanto(luz(5)>12 e ultra(1)>15)farei{frente(300)}
			parar()
			se(cor(5)=="PRETO")entao{
				interromper()
			}
			rotacionar(1000, 90)

}


///BACKUP DO CÒDIGO SO PARA GARANTIR.

numero travou = 0
numero sensor = 0
numero seguidor = 1
numero start = 0
numero preto = 0
numero triangulo = 0
numero vitima = 0
numero resgatepos = 0
numero vitimaCM = 0
booleano temp = verdadeiro
numero luz5 = 0
numero direc = 0
numero ULTRA2 = 0
numero ULTRA3 = 0
numero ULTIMO = 0
numero segueF = 180
numero luzPreto = 0
numero verde2 = 0
numero PERDEU = 0
numero tempCont = 0
booleano resgateF = falso
booleano pegar = falso
numero resgate90 = 0
numero saida = 0
tarefa seguelinha{
	se(luz(2)>20)entao{
		se(luz(3)>20)entao{
			frente(200)			
		} senao {
			zerartemporizador()
			esquerda(1000)
		}
	} senao{
		se(luz(3)>20)entao{
			zerartemporizador()
			direita(1000)
		} senao {
			parar()
			zerartemporizador()
			travou = travou + 1
			se(travou>3)entao{
				parar()
				tras(300)
				esperar(100)
				enquanto(cor(1)=="BRANCO" e cor(4)=="BRANCO")farei{frente(100)}
				parar()
				se(cor(1)=="PRETO")entao{
					frente(300)
					esperar(100)
					zerartemporizador()
					enquanto(cor(3)=="BRANCO" e temporizador()<2000)farei{direita(1000)}
					parar()
					se(cor(3)=="BRANCO")entao{
						enquanto(cor(2)=="BRANCO")farei{esquerda(1000)}
						parar()
					}
					zerartemporizador()
				} senao se(cor(4)=="PRETO")entao{
					frente(300)
					esperar(100)
					zerartemporizador()
					enquanto(cor(2)=="BRANCO" e temporizador()<2000)farei{esquerda(1000)}
					parar()
					se(cor(2)=="BRANCO")entao{
						enquanto(cor(3)=="BRANCO")farei{direita(1000)}
					}
				}
				travou = 0
			} senao {
				tras(200)
				esperar(50)
			}
		}
	}
}
tarefa curva90 {
	se(luz(1)<35)entao{
		zerartemporizador()
		tempCont = 0
		parar()
		frente(300)
		esperar(150)
		se(cor(1)=="VERDE" ou cor(4)=="VERDE" ou cor(2)=="VERDE" ou cor(3)=="VERDE")entao{
			enquanto(cor(1)=="VERDE" ou cor(4)=="VERDE" ou cor(2)=="VERDE" ou cor(3)=="VERDE")farei{frente(100)}
		}
		zerartemporizador()
		enquanto(cor(3)=="BRANCO" e temporizador()<3000)farei{direita(1000)}
		parar()
		se(cor(3)=="BRANCO")entao{
            tras(200)
            esperar(100)
            enquanto(cor(2)=="BRANCO")farei{esquerda(1000)}
        }
		zerartemporizador()
	} senao se(luz(4)<35)entao{
		zerartemporizador()
		tempCont = 0
		parar()
		frente(300)
		esperar(150)
		se(cor(1)=="VERDE" ou cor(4)=="VERDE" ou cor(2)=="VERDE" ou cor(3)=="VERDE")entao{
			enquanto(cor(1)=="VERDE" ou cor(4)=="VERDE" ou cor(2)=="VERDE" ou cor(3)=="VERDE")farei{frente(100)}
		}
		zerartemporizador()
		enquanto(cor(2)=="BRANCO" e temporizador()<3000)farei{esquerda(1000)}
		parar()
		se(cor(2)=="BRANCO")entao{
            tras(200)
            esperar(100)
            enquanto(cor(3)=="BRANCO")farei{direita(1000)}
        }
		parar()
		zerartemporizador()
	} senao {
		seguelinha()
	}
}
tarefa verde{
	se(cor(2)=="VERDE" ou cor(1)=="VERDE")entao{
		parar()
		zerartemporizador()
		enquanto(cor(3)=="BRANCO" e cor(2)=="VERDE")farei{frente(60)}
		parar()
		frente(100)
		esperar(50)
		parar()
		esperar(100)
		se(cor(3)=="VERDE" ou cor(4)=="VERDE")entao{
            enquanto(cor(3)=="VERDE" ou cor(4)=="VERDE")farei{esquerda(1000)}
            parar()
            se(cor(3)=="PRETO" ou cor(4)=="PRETO")entao{
                frente(300)
			    esperar(300)
			    direita(1000)
			    esperar(600)
			    enquanto(cor(3)=="BRANCO")farei{direita(1000)}
			    parar()
            } senao {
			    rotacionar(1000, 90)
			    enquanto(cor(2)=="BRANCO" e cor(3)=="BRANCO")farei{direita(1000)}
            }
		} senao {
			frente(300)
			esperar(300)
			direita(1000)
			esperar(600)
			enquanto(cor(3)=="BRANCO")farei{direita(1000)}
			parar()
		}
		zerartemporizador()
	} senao se(cor(3)=="VERDE" ou cor(4)=="VERDE")entao{
		parar()
		zerartemporizador()
		enquanto(cor(2)=="BRANCO" e cor(3)=="VERDE")farei{frente(60)}
		parar()
		frente(100)
		esperar(50)
		parar()
		esperar(100)
		se(cor(2)=="VERDE" ou cor(1)=="VERDE")entao{
            enquanto(cor(2)=="VERDE" ou cor(1)=="VERDE")farei{direita(500)}
            parar()
            se(cor(1)=="PRETO" ou cor(2)=="PRETO")entao{
                frente(300)
			    esperar(300)
			    esquerda(1000)
			    esperar(600)
			    enquanto(cor(2)=="BRANCO")farei{esquerda(1000)}
			    parar()
            } senao {
			    rotacionar(1000, 90)
			    enquanto(cor(2)=="BRANCO" e cor(3)=="BRANCO")farei{direita(1000)}
            }
		} senao {
			frente(300)
			esperar(300)
			esquerda(1000)
			esperar(600)
			enquanto(cor(2)=="BRANCO")farei{esquerda(1000)}
			parar()
		}
		zerartemporizador()
	} senao {
		curva90()
	}
}

tarefa obstaculo {
se (ultra(1) < 15) entao{
		zerartemporizador()
		se(cor(5)=="BRANCO" e luz(5)>45) entao {
			frente(100)
			esperar(100)
			parar()
			zerartemporizador()
		} senao{
			enquanto(ultra(1)<50)farei{direita(1000)}
			parar()
			rotacionar(1000, 20)
			frente(300)
			esperar(600)
			zerartemporizador()
			enquanto(cor(2)=="BRANCO" e (ultra(3)<50) e ultra(1)>15 e ultra(2)>25)farei{frente(100)}
			parar()
			se(cor(2)!="PRETO" e cor(3)!="PRETO")entao{
				rotacionar(1000, negativo(45))
				frente(300)
				esperar(300)
				enquanto(ultra(3)<50)farei{frente(300)}
				parar()
				rotacionar(1000, negativo(55))
				zerartemporizador()
				enquanto(cor(2)=="BRANCO" e temporizador()<2150)farei{frente(100)}
				parar()
				se(cor(2)!="PRETO" e cor(3)!="PRETO")entao{
					rotacionar(1000, negativo(40))
					enquanto(ultra(3)<50)farei{frente(300)}
					parar()
					rotacionar(1000, negativo(60))
					enquanto(cor(2)=="BRANCO")farei{frente(100)}
					parar()
					frente(300)
					esperar(300)
					rotacionar(1000, 60)
					zerartemporizador()
					enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
					parar()
				} senao{
					frente(300)
					esperar(300)
					rotacionar(1000, 55)
					zerartemporizador()
					enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
					parar()
				}
			} senao {
				frente(300)
				esperar(350)
				rotacionar(1000, 45)
				zerartemporizador()
				enquanto(toque(1)==falso e temporizador()<300)farei{tras(150)}
				parar()
			}
			zerartemporizador()
		}
		zerartemporizador()
	} senao{
		verde()
 	}
}
tarefa procurando{
			frente(300)
			esperar(100)
			parar()
			tras(300)
			esperar(100)
			parar()
			abrir(1)
			velocidadeatuador(150)
			baixar(1000)
			parar()
			enquanto((ultra(2)>ULTRA2 - 10 e ultra(3)>ULTRA3 - 5) e (ultra(1)>25 e temvitima()==falso))farei{
				frente(300)	
			}
			parar()
			se(temvitima()==verdadeiro)entao{
                velocidadeatuador(50)
				frente(300)
				levantar(1000)
                parar()
                levantar(500)
				fechar(1)
                rotacionar(1000, 180)
                enquanto(cor(5)=="BRANCO")farei{frente(300)}
                parar()
                velocidadeatuador(150)
			    girarbaixo(1000)
			    baixar(1000)
			    parar()
			    esperar(500)
			    levantar(1000)
			    girarcima(1000)
                rotacionar(1000, 180)
			} senao {
				fechar(1)
				levantar(1000)
			}
			parar()
}
tarefa procurandoSegundo{
			zerartemporizador()
			enquanto((ultra(2)>ULTRA2 - 10 e ultra(3)>ULTRA3 - 5) e (ultra(1)>20 e temporizador()<1000))farei{
				frente(300)
			}
}
tarefa resgate{
se(ultra(2)<50 e ultra(3)<50 e inclinacao()<350)entao{
      enquanto(ultra(2)<50 e ultra(3)<50)farei{seguelinha()}
		parar()
		velocidadeatuador(150)
		temp = falso
		acenderled("VERDE")
		preto = 0
		frente(300)
		esperar(600)
		se(ultra(3)<35)entao{
		frente(300)
		esperar(400)
		tras(300)
		esperar(400)
		parar()
		se(direcao()>230 e direcao()<300)entao{
			resgate90 = 270
			escrever(1, "270")
			rotacionar(1000, 5)
			enquanto(arredondar(direcao())!=270)farei{esquerda(1000)}
			parar()
		} senao se(direcao()>300 ou direcao()<40)entao{
			resgate90 = 0
			escrever(1, "0")
			rotacionar(1000, 5)
			enquanto(arredondar(direcao())!=0)farei{esquerda(1000)}
			parar()
		} senao se(direcao()>40 e direcao()<130)entao{
			resgate90 = 90
			escrever(1, "90")
			rotacionar(1000, 5)
			enquanto(arredondar(direcao())!=90)farei{esquerda(1000)}
			parar()
		} senao se(direcao()>130 e direcao()<230)entao{
			resgate90 = 180
			escrever(1, "180")
			rotacionar(1000, 5)
			enquanto(arredondar(direcao())!=180)farei{esquerda(1000)}
			parar()
		}
		comentar("Procurando pelo triangulo")
		enquanto(verdadeiro)farei{
			triangulo = triangulo + 1
            escrevernumero(1, saida)
			frente(300)
			esperar(300)
			tras(300)
			esperar(300)
			parar()
			se(toque(1)==falso)entao{
				se(triangulo==1)entao{saida=1}
				senao se(triangulo==2)entao{saida=2}
			}
			velocidadeatuador(150)
			abrir(1)
			baixar(600)
			enquanto(ultra(1)>120)farei{frente(300)}
			parar()
			levantar(600)
			fechar(1)
			velocidadeatuador(50)
			enquanto(luz(5)>12 e ultra(1)>15)farei{frente(300)}
			parar()
			se(cor(5)=="PRETO")entao{
				interromper()
			}
            se(ultra(3)>900 e triangulo==1)entao{
                saida = 3
            }senao se(triangulo == 1 e ultra(1)>1000)entao{
                saida = 1
            } senao se(triangulo==2 e ultra(1)>1000)entao{
                saida = 2
            } senao se(triangulo == 2)entao{
                tras(300)
                esperar(300)
                se(toque(1)!=falso)entao{
                    saida = 1
                }
            } senao se (triangulo==3 e ultra(3)>900) entao{
                saida = 2
            } senao se (triangulo==3 e ultra(1)>900) entao{
                saida = 3
            }
			rotacionar(1000, 90)

		}
		comentar("achou o tiangulo")
        se(temvitima()!=falso)entao{
            velocidadeatuador(150)
			girarbaixo(1000)
			baixar(1000)
			parar()
			esperar(1000)
			velocidadeatuador(150)
			levantar(1000)
			girarcima(1000)
			velocidadeatuador(50)
        }
		apagarled()
		rotacionar(1000, 40)
		frenterotacao(300, 25)
		rotacionar(1000, 45)
		acenderled("VERMELHO")
		parar()
		frente(300)
		esperar(400)
		apagarled()
	
		ULTRA2 = ultra(2)
		ULTRA3 = ultra(3)
		resgatepos = 0
		enquanto(verdadeiro)farei{
			escrevernumero(2, direcao())
			se(direcao()>230 e direcao()<300)entao{
				escrever(1, "270")
				rotacionar(1000, 5)
				enquanto(arredondar(direcao())!=270)farei{esquerda(1000)}
				parar()
			} senao se(direcao()>300 ou direcao()<40)entao{
				escrever(1, "0")
				rotacionar(1000, 5)
				enquanto(arredondar(direcao())!=0)farei{esquerda(1000)}
				parar()
			} senao se(direcao()>40 e direcao()<130)entao{
				escrever(1, "90")
				rotacionar(1000, 5)
				enquanto(arredondar(direcao())!=90)farei{esquerda(1000)}
				parar()
			} senao se(direcao()>130 e direcao()<230)entao{
				escrever(1, "180")
				rotacionar(1000, 5)
				enquanto(arredondar(direcao())!=180)farei{esquerda(1000)}
				parar()
			}
			escrevernumero(1, ultra(2))
			escrevernumero(2, ULTRA2)
			escrevernumero(3, resgatepos)
			ULTRA3 = ultra(3)
            ULTRA2 = ultra(2)
			direc = arredondar(direcao())
            zerartemporizador()

			se(ULTRA2>500)entao{
				enquanto(ultra(2)>500)farei{frente(150)}
                parar()
                pegar = falso
				ULTRA2 = ultra(2)
			}
            se(ULTRA2<150)entao{
                pegar = verdadeiro
            } senao{pegar = falso}

			se(resgatepos!=0)entao{
				procurandoSegundo()
				se(temporizador()>=1000)entao{
                    pegar = falso
					ULTRA2 = ultra(2)
					acenderled("VERMELHO")
				}
                zerartemporizador()
			} senao {procurando()}

			parar()
			se(ultra(1)<30)entao{
				parar()
				resgatepos = resgatepos + 1
				se(resgatepos==1)entao{
					trasrotacao(300,40)
					rotacionar(1000, 90)
				} senao{
					trasrotacao(300, 5)
					rotacionar(1000, 180)
				}
				apagarled()
				parar()
				acenderled("VERMELHO")
				enquanto(toque(1)==falso)farei{tras(300)}
				ULTRA2 = ultra(2)

			}
            se(resgatepos != 0)entao{pegar = falso}
			se(ULTRA2>150)entao{pegar = falso}
			se(ultra(2)<ULTRA2 - 5 ou pegar==verdadeiro)entao{
				pegar = falso
				parar()
				acenderled("VERDE")
				frente(200)
				esperar(200)
				parar()
				rotacionar(1000, 90)
				trasrotacao(300, 8)
				parar()
                abrir(1)
                baixar(1000)
				
				enquanto(temvitima()==falso e ultra(1)>30)farei{frente(300)}
				parar()
				se(ultra(1)<30)entao{
					se(resgatepos==0)entao{
						trasrotacao(1000, 100)
					} senao {
						trasrotacao(1000, 50)
					}
					rotacionar(1000, negativo(90))
				} senao {
					se(pegar==falso e 1==2)entao{
						enquanto(toque(1)==falso)farei{tras(300)}
						parar()
						frente(300)
						esperar(600)
						rotacionar(1000, negativo(90))
					} senao {
					velocidadeatuador(50)
					enquanto(temvitima()==falso e ultra(1)>30)farei{frente(300)}
					parar()
					frente(300)
					levantar(1000)
					parar()
					levantar(1000)
					fechar(1)
					se(temvitima()==falso)entao{
						parar()
						se(resgatepos==0)entao{
							enquanto(toque(1)==falso)farei{tras(300)}
							parar()
							frente(300)
							esperar(300)
						}senao se(resgatepos==2)entao{
							rotacionar(1000, negativo(90))
							enquanto(cor(2)=="VERDE")farei{frente(300)}
							verde()
						}senao {
							trasrotacao(1000, 50)
						}
						velocidadeatuador(150)
						levantar(1000)
						velocidadeatuador(50)
						rotacionar(1000, negativo(90))
					} senao{
						se(resgatepos==0)entao{
							rotacionar(1000, 90)
						}
						enquanto(ultra(1)>27)farei{frente(300)}
						parar()
						rotacionar(1000, 90)
						enquanto(luz(5)>12)farei{
							se(ultra(1)<40)entao{
								rotacionar(500, negativo(25))
							} senao {frente(300)}
						}
						parar()
						velocidadeatuador(150)
						girarbaixo(1000)
						baixar(1000)
						parar()
						esperar(500)
						velocidadeatuador(150)
						levantar(1000)
						girarcima(1000)
						velocidadeatuador(50)
						acenderled("VERMELHO")
						rotacionar(1000, 40)
						se(ultra(1)>40)entao{
							enquanto(ultra(1)>50)farei{frente(300)}
						} senao {
							enquanto(ultra(1)<50)farei{tras(300)}
						}
						parar()
						rotacionar(1000, 45)
						apagarled()
						resgatepos = 0
					}
					}
				}
                pegar = falso
			} senao se(ultra(3)<ULTRA3 - 1)entao{
				acenderled("PRETO")
				enquanto(ultra(3)>ULTRA3 - 5)farei{frente(300)}
				parar()
				frente(200)
				esperar(150)
				parar()
				rotacionar(1000, negativo(90))
				trasrotacao(300, 8)
                velocidadeatuador(150)
                abrir(1)
                baixar(1000)
				parar()
                enquanto(temvitima()==falso e ultra(1)>25)farei{frente(300)}
				parar()
				se(ultra(1)<5)entao{
					se(resgatepos==0)entao{
						trasrotacao(1000, 15)
					} senao{trasrotacao(1000, 50)}
					rotacionar(1000, 90)
				}senao{
					se(pegar==falso e 1==2)entao{
						enquanto(toque(1)==falso)farei{tras(300)}
						parar()
						frente(300)
						esperar(600)
						rotacionar(1000, negativo(90))
					} senao {
					parar()
					velocidadeatuador(50)
					frente(300)
					levantar(1000)
					parar()
					levantar(1000)
					fechar(1)
					comentar("Alteração aqui")
					se(temvitima()==falso)entao{
						rotacionar(1000, negativo(90))
						zerartemporizador()	
						enquanto(cor(2)!="VERDE" e ultra(1)>10)farei{frente(300)}
						parar()
						se(cor(2)!="VERDE")entao{
							rotacionar(1000, negativo(90))
							tras(300)
							esperar(100)
							enquanto(cor(2)=="BRANCO" e cor(3)=="BRANCO")farei{frente(300)}
							parar()
						}
						enquanto(verdadeiro)farei{
							temp = verdadeiro
							verde()
						}
					}
					se(resgatepos==0)entao{
						rotacionar(1000, negativo(90))
					} senao se(resgatepos==1)entao{
						rotacionar(1000, negativo(180))
					} senao se(resgatepos==2)entao{
						rotacionar(1000, 0)
					}

					enquanto(verdadeiro)farei{
					enquanto(luz(5)>12 e ultra(1)>40)farei{frente(300)}
					parar()

					se(ultra(1)<40)entao{
						enquanto(verdadeiro)farei{
							enquanto(luz(5)>12)farei{
								se(ultra(1)<40)entao{
									rotacionar(500, 90)
								} senao {frente(300)}
							}
							parar()
							interromper()
						}
						velocidadeatuador(120)
						baixar(650)
						velocidadeatuador(50)
						esperar(500)
						interromper()
					} senao {
						se(cor(5)=="PRETO")entao{
							velocidadeatuador(120)
							baixar(650)
							velocidadeatuador(50)
							esperar(500)
							velocidadeatuador(150)
							levantar(1000)
							rotacionar(1000, 10)
							interromper()
						}
					}
					}
					parar()
					velocidadeatuador(150)
					levantar(1000)
					enquanto(angulogiroatuador()>0)farei{girarbaixo(1)}
					parar()
					velocidadeatuador(50)
					acenderled("VERMELHO")
					rotacionar(1000, 60)
					se(ultra(1)>40)entao{
						enquanto(ultra(1)>50)farei{frente(300)}
					} senao {
						enquanto(ultra(1)<50)farei{tras(300)}
					}
					parar()
					rotacionar(1000, 70)
					apagarled()
					resgatepos = 0
					}
				}
			}
			
		}
		} senao {
			levantar(1000)
			tras(300)
			esperar(600)
		}
	} senao {obstaculo()}
}
inicio
velocidadeatuador(500)
levantar(900)
zerartemporizador()
enquanto(verdadeiro)farei{
	se(temporizador()>800 e temp==verdadeiro)entao{
		parar()
		zerartemporizador()
		enquanto(cor(3)=="BRANCO" e cor(1)=="BRANCO" e cor(2)=="BRANCO" e temporizador()<1500)farei{
			direita(1000)
		}
		parar()
		se(cor(1)=="BRANCO" e cor(2)=="BRANCO")entao{
			zerartemporizador()
			enquanto(cor(3)=="BRANCO" e cor(4)=="BRANCO" e temporizador()<3000)farei{
				esquerda(1000)
			}
			zerartemporizador()
			se(cor(3)=="BRANCO" e cor(4)=="BRANCO")entao{
				direita(1000)
				esperar(1500)
				se(tempCont == 0)entao{
					tras(200)
					esperar(820)
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
fim