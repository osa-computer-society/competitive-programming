(* solved 2021-01-10 *)

let ones_str n = List.nth ["zero";"one";"two";"three";"four";"five";"six";"seven";"eight";"nine";"ten";"eleven";"twelve";"thirteen";"fourteen";"fifteen";"sixteen";"seventeen";"eighteen";"nineteen"] n

let replace index str =
  let replace_aux =
  match int_of_string_opt str with
  | Some n -> if n < 20 then ones_str n
  else (
    let tens = n / 10 in
    let ones = n mod 10 in
    let tens_str = List.nth ["twenty";"thirty";"forty";"fifty";"sixty";"seventy";"eighty";"ninety"] (tens-2) in
    if ones = 0 then tens_str
    else tens_str ^ "-" ^ ones_str ones
  )
  | None -> str
  in if index = 0 then String.capitalize_ascii replace_aux else replace_aux ;;

try
  while true do
    read_line ()
    |> String.split_on_char ' '
    |> List.mapi replace
    |> String.concat " "
    |> print_endline
  done
with End_of_file -> ()

