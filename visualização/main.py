#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import pygame
import os
import traceback
from caixa import *
from molavertical import *

tamanhoTela = (300,700)
fps = None
if len(sys.argv) <= 3:
	time = 15.0
else:
	time = float(sys.argv[3])

_image_library = {}
def get_image(path):
        global _image_library
        image = _image_library.get(path)
        if image == None:
                canonicalized_path = path.replace('/', os.sep).replace('\\', os.sep)
                image = pygame.image.load(canonicalized_path)
                _image_library[path] = image
        return image

_sound_library = {}
def play_sound(path):
  global _sound_library
  sound = _sound_library.get(path)
  if sound == None:
    canonicalized_path = path.replace('/', os.sep).replace('\\', os.sep)
    sound = pygame.mixer.Sound(canonicalized_path)
    _sound_library[path] = sound
  sound.play()

def lerArquivoAnimacao(nomeArquivo):
	try:
		arquivo = open(nomeArquivo)

		passo = float(arquivo.readline())
		
		linhasArquivo = arquivo.readlines()
		
		animacao = []
		if len(sys.argv) <= 2:
			escala = 500.0
		else:
			escala = float(sys.argv[2])

		for linha in linhasArquivo:
			[y0,y1] = map(float,linha.split(','))
			animacao.append(((0.0,escala*y0),(0.0,escala*y1+64)))

		animacao = map(list,zip(*animacao))
		return passo, animacao

	except Exception, e:
		raise e

	
def renderizar(passo, animacao):
	def setMario():
		pygame.display.set_icon(get_image("assets/mario/caixa.png"))
		pygame.mixer.music.load('assets/mario/bgm.mp3')
		pygame.mixer.music.play(-1)
		background = get_image("assets/mario/background.png")
		caixaSprite = get_image("assets/mario/caixa.png")
		caixaSprite = pygame.transform.scale(caixaSprite,(64,64))
		caixa1 = Caixa(caixaSprite, animacao[0], tela)
		caixa2 = Caixa(caixaSprite, animacao[1], tela)
		return (caixa1,caixa2,background,cores["PRETO"])

	def setLua():
		pygame.display.set_icon(get_image("assets/luazinha/sun.png"))
		pygame.mixer.music.load('assets/luazinha/bgm.mp3')
		pygame.mixer.music.play(-1)
		background = get_image("assets/luazinha/background.png")
		newMoon = get_image("assets/luazinha/new_moon.png")
		fullMoon = get_image("assets/luazinha/full_moon.png")
		newMoon = pygame.transform.smoothscale(newMoon,(64,64))
		fullMoon = pygame.transform.smoothscale(fullMoon,(64,64))
		caixa1 = Caixa(newMoon, animacao[0], tela)
		caixa2 = Caixa(fullMoon, animacao[1], tela)
		return (caixa1,caixa2,background,cores["PRETO"])

	def setAdvanceWars():
		pygame.display.set_icon(get_image("assets/advance wars/soldado.png"))
		pygame.mixer.music.load('assets/advance wars/bgm.mp3')
		pygame.mixer.music.play(-1)
		background = get_image("assets/advance wars/background.png")
		soldadinho = get_image("assets/advance wars/soldado.png")
		aviao = get_image("assets/advance wars/avião.png")
		caixa1 = Caixa(aviao, animacao[0], tela)
		caixa2 = Caixa(soldadinho, animacao[1], tela)
		return (caixa1,caixa2,background,cores["NENHUMA"])

	def setLethalLeague():
		pygame.display.set_icon(get_image("assets/lethal league/bola.png"))
		pygame.mixer.music.load('assets/lethal league/bgm.mp3')
		pygame.mixer.music.play(-1)
		background = get_image("assets/lethal league/background.png")
		bola = get_image("assets/lethal league/bola.png")
		caixa1 = Caixa(bola, animacao[0], tela)
		caixa2 = Caixa(bola, animacao[1], tela)
		return (caixa1,caixa2,background,cores["PRETO"])

	cores = {"VERMELHO": (255,0,0), "AZUL": (0,0,255), "VERDE": (0,255,0), "PRETO": (0,0,0), "BRANCO": (255,255,255), "NENHUMA": -1}
	#tamanhoTela = (640,480)
	
	pygame.init()

	tela = pygame.display.set_mode(tamanhoTela)
	pygame.display.set_icon(get_image("assets/mario/caixa.png"))
	pygame.display.set_caption("Visualização do Sistema EDO")

	passoAtual = 0

	
	(caixa1,caixa2,background,cor) = setMario()
	mola1 = MolaVertical(cor,0,caixa1.retangulo.top,15,tamanhoTela[0]/2,10,tela)
	mola2 = MolaVertical(cor,caixa1.retangulo.bottom,caixa2.retangulo.top,15,tamanhoTela[0]/2,5,tela)

	aberto = True
	relogio = pygame.time.Clock()

	skip = 1
	if (fps > 60):
		print "fps=",fps
		print "skip=",(fps - 60)/60
		print "int(skip)=",int((fps - 60)/60)+1
		skip = int((fps - 60)/60)+1

	while aberto:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				aberto = False
				break
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_1:
					(caixa1,caixa2,background,cor) = setMario()
					(mola1.cor,mola2.cor) = (cor,)*2
				if event.key == pygame.K_2:
					(caixa1,caixa2,background,cor) = setLua()
					(mola1.cor,mola2.cor) = (cor,)*2
				if event.key == pygame.K_3:
					(caixa1,caixa2,background,cor) = setAdvanceWars()
					(mola1.cor,mola2.cor) = (cor,)*2
				if event.key == pygame.K_4:
					(caixa1,caixa2,background,cor) = setLethalLeague()
					(mola1.cor,mola2.cor) = (cor,)*2
				if event.key == pygame.K_5:
					pass

			# 	tela.blit(get_image("background.png"),(0,0))
			# 	mola1.desenharMola()
			# 	mola2.desenharMola()
			# 	caixa1.desenharProxPosicao()
			# 	caixa2.desenharProxPosicao()
			# 	mola1.yinicial = min(caixa1.retangulo.top,0);
			# 	mola1.yfinal = max(caixa1.retangulo.top,0);
			# 	mola2.yinicial = min(caixa1.retangulo.bottom,caixa2.retangulo.top)
			# 	mola2.yfinal = max(caixa1.retangulo.bottom,caixa2.retangulo.top)
			# 	pygame.display.flip()

		tela.blit(background,(0,0))
		if mola1.cor != cores["NENHUMA"]:
			mola1.desenharMola()
		if mola2.cor != cores["NENHUMA"]:
			mola2.desenharMola()
		caixa1.desenharProxPosicao(skip)
		caixa2.desenharProxPosicao(skip)
		mola1.yinicial = min(caixa1.retangulo.top,0);
		mola1.yfinal = max(caixa1.retangulo.top,0);
		mola2.yinicial = min(caixa1.retangulo.bottom,caixa2.retangulo.top)
		mola2.yfinal = max(caixa1.retangulo.bottom,caixa2.retangulo.top)
		pygame.display.flip()

		relogio.tick(min(60,fps))

def main():
	nomeArquivo = sys.argv[1]
	try:
		passo, animacao = lerArquivoAnimacao(nomeArquivo)
	except Exception, e:
		traceback.print_exc()
		print "Informe um nome de arquivo válido."
		sys.exit(1)

	global fps
	fps = (1+(20/passo))/time
	renderizar(passo, animacao)

if __name__ == '__main__':	
	main()
