macro(get_sources SOURCE_LIST DIR)
    set(FOLDER_NAMES generator graph_task truth_table_task task encoding_and_decoding_task)
    add_sources(${SOURCE_LIST} "${DIR}/sources" "${FOLDER_NAMES}")
endmacro()