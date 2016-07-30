odds (a:b:c) = b:(odds c)
odds [] = []

parse = map (map read . words) . odds . tail . lines
unparse = unlines . map show

rec _ _ [] = 0
rec [] c (x:xs) = rec [(x, c)] 1 xs
rec s@((x',c'):xcs) c (x:xs) =
	if x < x'
	then rec ((x,c):s) 1 xs
	else (x - x') * c' + rec xcs (c + c') (x:xs)

work :: [Integer] -> Integer
work = rec [] 1

main = interact $ unparse . map work . parse
