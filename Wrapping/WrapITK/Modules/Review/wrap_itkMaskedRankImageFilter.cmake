WRAP_CLASS("itk::MaskedRankImageFilter" POINTER_WITH_SUPERCLASS)
  foreach(d ${WRAP_ITK_DIMS})
    foreach(t ${WRAP_ITK_SCALAR})
      foreach(l ${WRAP_ITK_INT})
        WRAP_TEMPLATE("${ITKM_I${t}${d}}${ITKM_I${l}${d}}${ITKM_I${t}${d}}${ITKM_SE${d}}"    "${ITKT_I${t}${d}},${ITKT_I${l}${d}},${ITKT_I${t}${d}},${ITKT_SE${d}}")
      endforeach(l)
    endforeach(t)
  endforeach(d)
END_WRAP_CLASS()