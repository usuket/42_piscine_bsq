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
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}

TARGET=map2_2_0
echo ${TARGET}
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}

TARGET=map3_3_1
echo ${TARGET}
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}

TARGET=map10_10_2
echo ${TARGET}
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}

TARGET=map100_100_2
echo ${TARGET}
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}

TARGET=map1000_1000_2
echo ${TARGET}
time ./bsq input/${TARGET} > output/${TARGET}
diff output/${TARGET} verified/${TARGET}
