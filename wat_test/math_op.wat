(module
  (import "console" "log" (func $log (param i32)))
  (func (export "main") (local $r i32) (local $a i32) (local $b i32)
    (set_local $r (i32.const 0))
    (set_local $a (i32.const 2))
    (set_local $b (i32.const 5))

    (set_local $r (i32.add (get_local $a) (get_local $b)))
    (set_local $r (i32.sub (i32.const 6) (i32.const 4)))
    (set_local $r (i32.mul (get_local $a) (get_local $b)))
    (set_local $r (i32.div_s (get_local $a) (i32.const 1)))
    (set_local $r (i32.mul (get_local $a) (i32.const -1)))
    (set_local $r (i32.add (get_local $r) (i32.const 1)))
    (set_local $r (i32.sub (get_local $r) (i32.const 1)))

    (get_local $r)
    call $log)
)