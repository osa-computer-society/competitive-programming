(* solved 2021-01-10 *)

let rec can_build (maxw : int) (h : int) (w : int) (bricks : int list) =
  if h = 0 then "YES"
  else match bricks with
  | [] -> "NO"
  | hd :: tl -> (
  if hd = w then can_build maxw (h - 1) maxw tl
  else (
    if hd > w then "NO"
    else can_build maxw h (w - hd) tl
  )
  ) ;;

let line = read_line () in
let tokens = List.map int_of_string (String.split_on_char ' ' line) in
let h = List.nth tokens 0 in
let w = List.nth tokens 1 in
let bricks = List.map int_of_string (String.split_on_char ' ' (read_line ())) in
begin
  print_endline (can_build w h w bricks)
end
