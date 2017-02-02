# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 18:33:55 by ysakakib          #+#    #+#              #
#    Updated: 2017/02/01 18:33:57 by ysakakib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET=map1_1_1
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map2_2_0
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map3_3_1
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map10_10_2
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map100_100_2
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map1000_1000_2
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l

TARGET=map15_15_all_empty
echo ${TARGET}
time ./bsq t_input/${TARGET} > t_output/${TARGET}
diff t_output/${TARGET} t_verified/${TARGET} | wc -l
