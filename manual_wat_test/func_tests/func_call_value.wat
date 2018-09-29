(module
  (import "console" "log" (func $log (param i32)))
  (func $sum (param $a i32) (param $b i32) (result i32)
    (local $s i32)
    (set_local $s
      (i32.add
        (get_local $a)
        (get_local $b)
      )
    )
    (return (get_local $s))
  )
  (func (export "main") (result i32)
    (local $c i32)
    (local $d i32)
    (local $somma i32)
    (set_local $c (i32.const 1))
    (set_local $d (i32.const 2))

    (set_local $somma
      (call $sum
        (get_local $c)
        (get_local $d)
      )
    )
    
    (call $log
      (get_local $somma)
    )

    (return (i32.const 0))
  )
)
