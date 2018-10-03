(module

  (import "console" "int_log" (func $int_log (param i32)))
  (import "console" "str_log" (func $str_log (param i32) (param i32)))
  (import "js" "mem" (memory 1))

  (data (i32.const 0) "Sum of first 10 number is")
  (data (i32.const 25) "NOT case\n")
  (data (i32.const 35) "AND case\n")
  (data (i32.const 45) "OR case\n")

  (func (export "main") (result i32)

    (local $N i32)
    (local $i i32)
    (local $t i32)
    (local $sum i32)
    (local $cond i32)
    (set_local $N (i32.const 10))
    (set_local $sum (i32.const 0))
    (set_local $cond (i32.const 5))
    
    (set_local $i (i32.const 0))
    (set_local $t (i32.const 10))
    (loop $loop0
      (set_local $sum (i32.add (get_local $sum) (get_local $i)))

      (set_local $i (i32.add (get_local $i) (i32.const 1)))
      (set_local $t (i32.sub (get_local $t) (i32.const 1)))
      (br_if $loop0
        (i32.lt_s (get_local $i) (get_local $N))
      )
    )
    (call $str_log
      (i32.const 0)
      (i32.const 25)
    )
    (call $int_log (get_local $sum))
    (if (i32.eq (i32.eqz (get_local $cond)) (i32.const 5))
      (then
        (call $str_log
          (i32.const 25)
          (i32.const 10)
        )
      )
      (else
        
        (if (i32.and (i32.lt_s (get_local $cond) (i32.const 7)) (i32.gt_s (get_local $cond) (i32.const 3)))
          (then
            (call $str_log
              (i32.const 35)
              (i32.const 10)
            )
          )
          (else
            (if (i32.or (i32.gt_s (get_local $cond) (i32.const 2)) (i32.lt_s (get_local $cond) (i32.const 1)))
              (then
                (call $str_log
                  (i32.const 45)
                  (i32.const 9)
                )
              )
            )
          )
        )
      )
    )
    (return (i32.const 0))
  )
)