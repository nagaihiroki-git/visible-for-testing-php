PHP_ARG_ENABLE(visible_for_testing, whether to enable visible_for_testing support,
[ --enable-visible_for_testing   Enable visible_for_testing support])

if test "$PHP_VISIBLE_FOR_TESTING" != "no"; then
    PHP_NEW_EXTENSION(visible_for_testing, src/visible_for_testing.c, $ext_shared)
    PHP_SUBST(VISIBLE_FOR_TESTING_SHARED_LIBADD)
fi
