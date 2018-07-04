#!/bin/bash

HERE=`pwd`

export resincl=${SIGALI_resolver}/res/export
export tddincl=${SIGALI_resolver}/tdd/export
export memincl=${SIGALI_resolver}/mem/export

export resolver_export=${SIGALI_resolver}/export
export resolver_dir=${resolver_export}

if ([ "$1" = "force" ]); then
    \rm ${resolver_dir}/*
fi
  
echo "Begin Memory Compilation"
cd ${SIGALI_resolver}/mem
$MAKE $1
echo ""

echo "Begin TDD Compilation"
cd ${SIGALI_resolver}/tdd
$MAKE $1
echo ""

echo "Begin Resolver Compilation"
cd ${SIGALI_resolver}/res
$MAKE $1
echo ""

cd ${SIGALI_resolver}

mkdir -p ${resolver_dir}

\cp -p ${SIGALI_resolver}/mem/export/*.o ${resolver_dir}/.
\cp -p ${SIGALI_resolver}/res/export/*.o ${resolver_dir}/.  
\cp -p ${SIGALI_resolver}/tdd/export/*.o ${resolver_dir}/.

\cp -p ${SIGALI_resolver}/mem/export/*.h ${resolver_dir}/.
\cp -p ${SIGALI_resolver}/tdd/export/*.h ${resolver_dir}/.
\cp -p ${SIGALI_resolver}/res/export/*.h ${resolver_dir}/.

echo "Resolver building--done" 
cd  $HERE 
 
