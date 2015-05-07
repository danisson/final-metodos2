import pygame

class Massa():
	def __init__(self,width,height,color,animation,screen):
		self.width = width
		self.height = height

		self.image = pygame.Surface([width,height])

		self.image.fill(color)
		self.rect = self.image.get_rect()

		self.animation = animation
		self.screen = screen
		