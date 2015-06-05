from __future__ import division
import pygame

class MolaVertical():
	def __init__(self,yinicial,yfinal,largura,alinhamentoX,voltas,tela):
		self.yinicial = yinicial
		self.yfinal = yfinal
		self.alinhamentoX = alinhamentoX
		self.largura = largura
		self.voltas = voltas
		self.tela = tela

	def desenharMola(self):
		zigzag = abs(self.yfinal - self.yinicial)
		tamanhoVolta = zigzag/self.voltas
		
		pontos = []
		pontos.append((self.alinhamentoX,self.yinicial))
		atualX = self.alinhamentoX-self.largura//2
		atualY = self.yinicial + tamanhoVolta//2
		pontos.append((atualX,atualY))
		for i in xrange(0,self.voltas-1):
			if (i%2)==0:
				atualX = self.alinhamentoX + self.largura//2
			else:
				atualX = self.alinhamentoX - self.largura//2
			atualY = atualY + tamanhoVolta
			pontos.append((atualX,atualY))

		pontos.append((self.alinhamentoX,self.yfinal))
		pygame.draw.aalines(self.tela,(255,255,255),False,pontos,1)
