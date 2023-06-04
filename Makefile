# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:06:52 by caesemar          #+#    #+#              #
#    Updated: 2023/06/03 15:46:21 by jocasado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = push_swap
RM = rm -rf
HDRS = -I ./headers/
################################################################################
##								               MANDATORY									                  ##
################################################################################
CFILES = \
		libft/ft_strlen.c \
		libft/ft_bzero.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_split.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_isdigit.c\
		libft/ft_atoi.c\
		libft/ft_itoa.c\
		source/algorithm_utils.c\
		source/algorithm_utils3.c\
		source/algorithm_utils2.c\
		source/utils.c\
		source/utils2.c\
		source/utils3.c\
		source/ps_moves.c\
		source/input_checker.c\
		source/print_moves.c\
		source/print_moves1.c\
		source/push_swap.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
################################################################################
.PHONY: all re fclean clean tests_l tests_m
################################################################################

all:        $(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)compiling ..."
			@$(CC) $(OBJS) -o  $(NAME)
			@echo "$(GREEN)compiled:$(NAME) build ✅"
.c.o:
			@${CC} ${CFLAGS} $^ -o $@ ${HDRS}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)deleting...\n$(RED)$(NAME) deleted"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)deleting...\n$(RED)$(OBJS) deleted"

tests_l: test1_l test2_l test3_l test4_l
		@echo "$(GREEN)tests done ✅ $(DEFAULT)"

test1_l:
		
			@echo "$(GREEN)##3 NUMBERS##$(DEFAULT)"		
			@echo "./$(NAME) $(ARG2)\n"	
			@./$(NAME) $(ARG1) | ./checker_linux $(ARG1)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG1) | wc -l

test2_l:
			@echo "$(GREEN)##5 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG2)\n"	
			@./$(NAME) $(ARG2) | ./checker_linux $(ARG2)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG2) | wc -l
test3_l:
			@echo "$(GREEN)##100 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG3)\n"	
			@./$(NAME) $(ARG3) | ./checker_linux $(ARG3)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG3) | wc -l
test4_l:
			@echo "$(GREEN)##500 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG4)\n"	
			@./$(NAME) $(ARG4) | ./checker_linux $(ARG4)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG4) | wc -l

tests_m: test1_m test2_m test3_m test4_m
		@echo "$(GREEN)tests done ✅ $(DEFAULT)"

test1_m:
		
			@echo "$(GREEN)##3 NUMBERS##$(DEFAULT)"		
			@echo "./$(NAME) $(ARG1)\n"	
			@./$(NAME) $(ARG1) | ./checker_Mac $(ARG1)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG1) | wc -l

test2_m:
			@echo "$(GREEN)##5 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG2)\n"	
			@./$(NAME) $(ARG2) | ./checker_Mac $(ARG2)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG2) | wc -l
test3_m:
			@echo "$(GREEN)##100 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG3)\n"	
			@./$(NAME) $(ARG3) | ./checker_Mac $(ARG3)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG3) | wc -l
test4_m:
			@echo "$(GREEN)##500 NUMBERS##$(DEFAULT)"
			@echo "./$(NAME) $(ARG4)\n"	
			@./$(NAME) $(ARG4) | ./checker_Mac $(ARG4)
			@echo "Move number: $(GREEN)"
			@./$(NAME) $(ARG4) | wc -l

test_error1:
			@echo "$(GREEN)##ERROR ARGUMENTS 1##$(DEFAULT)"
			@echo "./$(NAME) $(ARG_ERR1)\n"
			@./$(NAME) $(ARG_ERR1)
test_error2:
			@echo "$(GREEN)##ERROR ARGUMENTS 2##$(DEFAULT)"
			@echo "./$(NAME) $(ARG_ERR2)\n"
			@./$(NAME) $(ARG_ERR2)
test_error3:
			@echo "$(GREEN)##ERROR ARGUMENTS 3##$(DEFAULT)"
			@echo "./$(NAME) $(ARG_ERR3)\n"
			@./$(NAME) $(ARG_ERR3)	
test_error4:
			@echo "$(GREEN)##ERROR ARGUMENTS 4##$(DEFAULT)"
			@echo "./$(NAME) $(ARG_ERR4)\n"
			@./$(NAME) $(ARG_ERR4)
test_error5:
			@echo "$(GREEN)##ERROR ARGUMENTS 5##$(DEFAULT)"
			@echo "./$(NAME) $(ARG_ERR5)\n"
			@./$(NAME) $(ARG_ERR5)


##COLOURS##
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
DEFAULT = \033[0m

##ARGUMENTS##
ARG1="0 3 2"
ARG2="-5 -7 8 5 0"
ARG3="54 9 37 8 68 93 86 16 46 55 42 96 31 100 79 3 94 78 45 27 12 41 49 76 52 90 48 19 23 89 80 29 22 18 66 4 15 53 61 82 85 83 28 25 73 67 71 35 40 65 98 75 92 43 21 88 81 30 69 62 44 99 2 24 91 32 64 14 10 74 58 97 11 26 59 56 1 51 17 20 87 39 50 34 13 38 95 60 47 7 77 57 70 63 84 36 6 5 33 72"
ARG4="287 389 213 452 144 472 398 79 268 225 368 362 314 71 433 284 28 65 202 51 82 386 126 305 382 248 187 135 427 102 199 322 454 21 67 43 461 308 397 245 20 32 458 36 290 359 111 376 108 418 431 23 281 448 7 66 467 469 343 332 45 357 49 414 347 157 286 229 236 438 395 211 143 342 194 455 240 37 259 323 430 439 301 116 219 329 484 311 396 13 406 417 190 426 334 31 254 374 441 93 296 365 475 440 410 482 247 400 209 232 383 147 212 224 171 260 447 390 101 234 437 177 337 151 64 404 130 401 198 129 237 18 241 142 205 425 11 160 391 485 50 38 320 91 415 107 174 496 6 493 253 89 104 462 313 86 353 192 83 306 44 218 178 335 303 210 99 263 196 500 206 235 216 56 180 271 96 435 377 403 200 188 451 327 87 12 481 304 498 186 220 339 85 495 424 197 279 148 453 114 132 471 221 112 490 381 55 363 191 244 351 246 288 52 249 367 352 478 310 428 487 8 193 328 30 494 27 243 208 22 40 316 272 117 265 94 412 189 98 361 25 53 34 422 68 141 402 105 470 473 146 419 416 341 176 46 179 413 100 33 255 238 226 317 164 154 156 387 175 24 41 16 172 261 230 5 264 3 283 423 110 299 405 399 319 326 19 77 75 421 258 442 480 298 204 118 269 163 48 9 228 76 61 354 459 333 355 57 14 457 69 407 464 266 312 429 128 273 70 434 385 103 465 446 456 294 295 309 242 411 17 394 350 324 231 445 366 183 153 95 222 251 173 378 47 26 373 302 436 267 486 203 217 340 35 477 214 15 145 59 388 345 280 336 479 4 207 166 215 420 233 81 369 140 136 277 252 138 285 73 307 384 39 257 84 444 356 63 476 318 167 450 360 159 72 120 62 432 488 466 275 331 161 185 158 1 88 262 256 491 29 364 497 131 149 80 134 124 58 125 165 97 137 371 121 330 74 289 123 468 379 358 443 483 139 60 489 292 293 278 182 492 282 325 109 150 321 133 409 227 106 10 155 54 348 168 152 338 392 181 499 291 113 370 300 78 250 463 169 127 2 408 162 115 270 42 170 346 315 119 90 276 297 344 92 239 201 460 349 274 474 184 122 449 223 372 393 195 375 380"
##ARGS ERROR##
ARG_ERR1="0 1 2 3 4 5 0"
ARG_ERR2=""
ARG_ERR3="0 5 7 123+4"
ARG_ERR4="12 45 656 17281728748434"
ARG_ERR5="2837 395 4595 945 a 92839"









